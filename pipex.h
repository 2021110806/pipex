/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 20:31:29 by minjeon2          #+#    #+#             */
/*   Updated: 2023/07/11 19:41:07 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX__H
# define PIPEX__H

# include "./libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# define STDIN 0
# define STDOUT 1
# define READ 0
# define WRITE 1
# define STDERR 2

typedef struct	s_args_saver
{
    int		infile;
	char	**cmd1;
	char	**cmd2;
	int		outfile;
	char	*path;

} t_args_saver;

typedef struct s_pipe_info
{
	int	pipe_fds[2];
	int	status;
	int	pid1;
	int	pid2;
} t_pipe_info;

void	manage_input_args(t_args_saver *cmd_saver, char ** argv, char **envp);
int		set_path(char **envp, t_args_saver *args_saver, int cmd);
int		print_error();
#endif