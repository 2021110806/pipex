#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_args_saver	cmd_saver;
	int				pipe_fds[2];
	pid_t			pid;
	int				status;

	manage_input_args(&cmd_saver, argv, envp);
	dup2(cmd_saver.infile, STDIN);
	dup2(cmd_saver.outfile, STDOUT);

	if (pipe(pipe_fds))
		printf("Error");
	pid = fork();
	if (pid == -1)
		printf("Error");
	else if (pid == 0)
	{
		close(pipe_fds[READ]);
		dup2(cmd_saver.infile, STDIN);
		dup2(pipe_fds[WRITE], STDOUT);
		set_path(envp, &cmd_saver, 1);
		execve(cmd_saver.path, cmd_saver.cmd1, envp);
	}
	else
	{
		wait(&status);
		close(pipe_fds[WRITE]);
		dup2(pipe_fds[READ], STDIN);
		dup2(cmd_saver.outfile, STDOUT);
		set_path(envp, &cmd_saver, 2);
		execve(cmd_saver.path, cmd_saver.cmd2, envp);
	}
}