#include "pipex.h"

int	excute_cmd1(t_pipe_info pipe_info, char **envp, char **argv)
{
	t_args_saver cmd_saver;

	if (!manage_input_args(&cmd_saver, argv, INFILE_OPEN))
		exit(1);
	close(pipe_info.pipe_fds[READ]);
	if (dup2(cmd_saver.infile, STDIN) == -1)
		return (print_error(0, 0));
	if (dup2(pipe_info.pipe_fds[WRITE], STDOUT) == -1)
		return (print_error(0, 0));
	if (!set_path(envp, &cmd_saver, 1))
	{
		ft_putstr_fd("pipex: ", STDERR);
		ft_putstr_fd(cmd_saver.cmd1[0], STDERR);
		ft_putstr_fd(": command not found", STDERR);
		ft_putstr_fd("\n", STDERR);
		return (0);
	}
	system("leaks pipex");
	if (execve(cmd_saver.path, cmd_saver.cmd1, envp) == -1)
		return (print_error(0, 0));
	return (1);
}

int	excute_cmd2(t_pipe_info pipe_info, char **envp, char **argv)
{
	t_args_saver cmd_saver;

	if (!manage_input_args(&cmd_saver, argv, OUTFILE_OPEN))
		exit(1);
	close(pipe_info.pipe_fds[WRITE]);
	if (dup2(pipe_info.pipe_fds[READ], STDIN) == -1)
		print_error(0, 0);
	if (dup2(cmd_saver.outfile, STDOUT) == -1)
		print_error(0, 0);
	if (!set_path(envp, &cmd_saver, 2))
	{
		ft_putstr_fd("pipex: ", STDERR);
		ft_putstr_fd("command not found: ", STDERR);
		ft_putstr_fd(cmd_saver.cmd2[0], STDERR);
		ft_putstr_fd("\n", STDERR);
		return (0);
	}
	system("leaks pipex");
	if (execve(cmd_saver.path, cmd_saver.cmd2, envp) == -1)
		print_error(0, 0);
	return (1);
}

int	excute_parent_process(t_pipe_info pipe_info)
{
	close(pipe_info.pipe_fds[READ]);
	close(pipe_info.pipe_fds[WRITE]);
	system("leaks pipex");
	waitpid(pipe_info.pid1, &pipe_info.status, 0);
	waitpid(pipe_info.pid2, &pipe_info.status, 0);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipe_info		pipe_info;

	if (argc != 5)
	{
		ft_putstr_fd("pipex: invalid input\n", STDERR);
		exit(1);
	}
	if (pipe(pipe_info.pipe_fds))
		print_error(0, 0);
	pipe_info.pid1 = fork();
	if (pipe_info.pid1 == -1)
	{
		print_error(0, 0);
		exit(1);
	}
	if (pipe_info.pid1 != 0)
	{
		pipe_info.pid2 = fork();
		if (pipe_info.pid2 == -1)
		{
			print_error(0, 0);
			exit(1);
		}
		if (pipe_info.pid2 != 0)
			excute_parent_process(pipe_info);
		if (pipe_info.pid2 == 0 && !excute_cmd1(pipe_info, envp, argv))
			exit(1);
	}
	else
	{
		if (!excute_cmd2(pipe_info, envp, argv))
			exit(1);
	}
}
