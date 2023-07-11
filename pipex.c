#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_args_saver	cmd_saver;
	int				pipe_fds[2];
	pid_t			pid;
	int				status;

	if (argc != 5)
	{
		ft_putstr_fd("invalid input", 1);
		return (1);
	}
	manage_input_args(&cmd_saver, argv, envp);
	dup2(cmd_saver.infile, STDIN);
	dup2(cmd_saver.outfile, STDOUT);
	if (pipe(pipe_fds))
		print_error();
	pid = fork();
	if (pid == -1)
		print_error();
	else if (pid == 0)
	{
		close(pipe_fds[READ]);
		if (dup2(cmd_saver.infile, STDIN) == -1)
			print_error();
		if (dup2(pipe_fds[WRITE], STDOUT) == -1)
			print_error();
		if (!set_path(envp, &cmd_saver, 1))
		{
			ft_putstr_fd("pipex :",1);
			ft_putstr_fd("command not found",1);
			ft_putstr_fd(cmd_saver.cmd1, 1);
		}
		if (execve(cmd_saver.path, cmd_saver.cmd1, envp) == -1)
			print_error();
	}
	else
	{
		wait(&status);
		close(pipe_fds[WRITE]);
		if (dup2(pipe_fds[READ], STDIN) == -1)
			print_error();
		if (dup2(cmd_saver.outfile, STDOUT) == -1)
			print_error();
		if (!set_path(envp, &cmd_saver, 2))
		{
			ft_putstr_fd("pipex :",1);
			ft_putstr_fd("command not found",1);
			ft_putstr_fd(cmd_saver.cmd1, 1);
		}
		if (execve(cmd_saver.path, cmd_saver.cmd2, envp) == -1)
			print_error();
	}
}