#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_args_saver	cmd_saver;
	int				pipe_fds[2];
	pid_t			pid1;
	pid_t			pid2;
	int				status1;
	int				status2;

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
	pid1 = fork();
	if (pid1 != 0)
	{
		pid2 = fork();
		if (pid2 != 0)
		{
			//waitpid(pid1,&status1,0);
			waitpid(pid2,&status2,0);
			printf("status1 : %d\n",WIFEXITED(status1));
			printf("status2 : %d\n",WIFEXITED(status2));
		}
		else
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
				ft_putstr_fd(cmd_saver.cmd1[0], 1);
			}
			if (execve(cmd_saver.path, cmd_saver.cmd1, envp) == -1)
				print_error();
		}
	}
	else
	{
		close(pipe_fds[WRITE]);
		if (dup2(pipe_fds[READ], STDIN) == -1)
			print_error();
		if (dup2(cmd_saver.outfile, STDOUT) == -1)
			print_error();
		if (!set_path(envp, &cmd_saver, 2))
		{
			ft_putstr_fd("pipex :",1);
			ft_putstr_fd("command not found",1);
			ft_putstr_fd(cmd_saver.cmd2[0], 1);
		}
		if (execve(cmd_saver.path, cmd_saver.cmd2, envp) == -1)
			print_error();
	}
}