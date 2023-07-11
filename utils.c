#include "pipex.h"

int	print_error()
{
	perror("pipex:");
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
	char	*res;
	char	*path_finded;

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

void	manage_input_args(t_args_saver *cmd_saver, char **argv, char **envp)
{
	cmd_saver->infile = open("./infile", O_RDONLY);
	cmd_saver->cmd1 = ft_split(argv[2],' ');
	cmd_saver->cmd2 = ft_split(argv[3],' ');
	cmd_saver->outfile = open("./outfile", O_WRONLY | O_CREAT | O_TRUNC, 0644);
}