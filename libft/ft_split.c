/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <minjeon2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:03:08 by minjeon2          #+#    #+#             */
/*   Updated: 2023/03/26 00:49:29 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	*free_arr(char **arr, int idx)
{
	int	i;

	i = 0;
	while (i < idx)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return ((void *)0);
}

static int	is_word(char inp, char c)
{
	if (inp == c)
		return (0);
	return (1);
}

static int	calc_word_len(char const *inp, char c)
{
	int	inp_i;

	inp_i = 0;
	while (inp[inp_i] && is_word(inp[inp_i], c))
		inp_i++;
	return (inp_i);
}

static int	count_word(char const *str, char c)
{
	int	how_many_word;
	int	i;

	i = 0;
	how_many_word = 0;
	while (str[i] != '\0')
	{
		if (is_word(str[i], c) && str[i] != '\0')
		{
			while (is_word(str[i], c) && str[i] != '\0')
				i++;
			how_many_word++;
		}
		while (!is_word(str[i], c) && str[i] != '\0')
			i++;
	}
	return (how_many_word);
}

char	**ft_split(char const *str, char c)
{
	char	**return_value;
	int		i;
	int		j;

	return_value = (char **) malloc (8 * (count_word(str, c) + 1));
	if (!(return_value))
		return ((void *)0);
	i = 0;
	while (*str != '\0' && count_word(str, c) != 0)
	{
		j = 0;
		while (!is_word(*str, c) && *str)
			str++;
		if (calc_word_len(str, c))
		{
			return_value[i] = (char *) malloc ((calc_word_len(str, c) + 1));
			if (!return_value[i])
				return (free_arr(return_value, i));
			while (is_word(*str, c) && *str)
				return_value[i][j++] = *str++;
			return_value[i++][j] = '\0';
		}
	}
	return_value[i] = 0;
	return (return_value);
}
