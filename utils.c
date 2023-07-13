/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 03:33:20 by minjeon2          #+#    #+#             */
/*   Updated: 2023/07/13 16:39:20 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	print_error(int is_invalid_argc, int is_file_related, char *file_name)
{
	if (is_invalid_argc)
	{
		ft_putstr_fd("pipex: invalid input\n", STDERR);
		return (1);
	}
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
	i = 0;
	while (path_list[i])
	{
		target_path = ft_strjoin(ft_strdup("/"), path_list[i]);
		target_path = ft_strjoin(target_path, "/");
		if (cmd == 1)
			target_path = ft_strjoin(target_path, args_saver -> cmd1[0]);
		if (cmd == 2)
			target_path = ft_strjoin(target_path, args_saver -> cmd2[0]);
		if (access(target_path, F_OK) == 0)
		{
			args_saver -> path = target_path;
			free_arr(path_list);
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
			return (print_error(0, 1, argv[1]));
	}
	cmd_saver->cmd1 = ft_split(argv[2], ' ');
	cmd_saver->cmd2 = ft_split(argv[3], ' ');
	if (file_checker)
	{
		cmd_saver->outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (cmd_saver-> outfile < 0)
			return (print_error(0, 1, argv[4]));
	}
	return (1);
}
