#include "pipex.h"

int	set_path(char **envp, t_args_saver *args_saver, int cmd)
{
	int		i;
	char	**path_list;
	char	*target_path;
	char	*res;
	char	*path_finded;

	i = 0;
	while ((*envp)[i])
	{
		if (ft_strlen(*envp) > 5)
		{
			// printf("path_finded: %s\n",envp[i]);
			if (envp[i][0] == 'P' && envp[i][1] == 'A' && \
			envp[i][2] == 'T' && envp[i][3] == 'H' && envp[i][4] == '=')
			{
				path_finded = (&((envp)[i][5]));
				break;
			}
		}
		i++;
	}
	// printf("make_path_list\n");
	path_list = ft_split(path_finded, ':');
	target_path = ft_strdup("/");
	i = 0;
	while (path_list[i])
	{
		// printf("path_list[%d] = %s\n",i,path_list[i]);
		target_path = ft_strjoin(path_list[i], "/");
		if (cmd == 1)
				target_path = ft_strjoin(target_path, args_saver -> cmd1[0]);
		if (cmd == 2)
			target_path = ft_strjoin(target_path, args_saver -> cmd2[0]);
		if (access(target_path, F_OK) == 0)
		{
			args_saver -> path = target_path;
			// printf("target_path:%s\n",target_path);
			return (1);
		}
		i++;
	}
	return (0);
}

void	manage_input_args(t_args_saver *cmd_saver, char ** argv, char **envp)
{
	cmd_saver->infile = open("./infile", O_RDONLY);
	cmd_saver->cmd1 = ft_split(argv[2],' ');
	cmd_saver->cmd2 = ft_split(argv[3],' ');
	cmd_saver->outfile = open("./outfile", O_WRONLY | O_CREAT | O_TRUNC, 0644);
}