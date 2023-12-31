/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 20:31:29 by minjeon2          #+#    #+#             */
/*   Updated: 2023/07/13 17:17:51 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

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
# define INFILE_OPEN 0
# define OUTFILE_OPEN 1

typedef struct s_args_saver
{
	int		infile;
	char	**cmd1;
	char	**cmd2;
	int		outfile;
	char	*path;
}	t_args_saver;

typedef struct s_pipe_info
{
	int	pipe_fds[2];
	int	status;
	int	pid1;
	int	pid2;
}	t_pipe_info;

int		manage_input_args(t_args_saver *cmd_saver, char **argv, \
						int file_checker);
int		set_path(char **envp, t_args_saver *args_saver, int cmd);
int		print_error(int is_invalid_argc, int is_file_related, \
					char *file_name);
int		excute_cmd1(t_pipe_info pipe_info, char **envp, char **argv);
int		excute_cmd2(t_pipe_info pipe_info, char **envp, char **argv);
int		excute_parent_process(t_pipe_info pipe_info);
#endif