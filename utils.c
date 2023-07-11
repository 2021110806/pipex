#include "pipex.h"

int	print_error(int is_file_related, char* file_name)
{
	if (is_file_related)
	{
		ft_putstr_fd("pipex: ", STDERR);
		ft_putstr_fd(file_name, STDERR);
		ft_putstr_fd(": ", STDERR);
		perror(0);
		return (0);
	}
	perror("pipex: ");
	return (0);
}

char	*find_path_startpoint(char **envp)
{
	int		i;

	i = 0;
	while ((*envp)[i])
	{
		if (ft_strlen(*envp) > 5)
		{
			if (envp[i][0] == 'P' && envp[i][1] == 'A' && \
			envp[i][2] == 'T' && envp[i][3] == 'H' && envp[i][4] == '=')
				return (&((envp)[i][5]));
		}
		i++;
	}
	return (0);
}

int	set_path(char **envp, t_args_saver *args_saver, int cmd)
{
	int		i;
	char	**path_list;
	char	*target_path;

	path_list = ft_split(find_path_startpoint(envp), ':');
	target_path = ft_strdup("/");
	i = 0;
	while (path_list[i])
	{
		target_path = ft_strjoin(path_list[i], "/");
		if (cmd == 1)
				target_path = ft_strjoin(target_path, args_saver -> cmd1[0]);
		if (cmd == 2)
			target_path = ft_strjoin(target_path, args_saver -> cmd2[0]);
		if (access(target_path, F_OK) == 0)
		{
			args_saver -> path = target_path;
			return (1);
		}
		i++;
	}
	return (0);
}

int	manage_input_args(t_args_saver *cmd_saver, char **argv, int file_checker)
{
	if (!file_checker)
	{
		cmd_saver->infile = open(argv[1], O_RDONLY);
		if (cmd_saver-> infile < 0)
			return (print_error(1, argv[1]));
	}
	cmd_saver->cmd1 = ft_split(argv[2],' ');
	cmd_saver->cmd2 = ft_split(argv[3],' ');
	if (file_checker)
	{
		cmd_saver->outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (cmd_saver-> outfile < 0)
			return (print_error(1, argv[4]));
	}
	return (1);
}