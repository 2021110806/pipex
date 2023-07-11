/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <minjeon2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:33:05 by minjeon2          #+#    #+#             */
/*   Updated: 2023/03/16 21:13:40 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static unsigned int	min_len(char *inp1, char *inp2)
{
	int	return_value1;
	int	return_value2;

	return_value1 = 0;
	return_value2 = 0;
	while (inp1[return_value1])
	{
		return_value1++;
	}
	while (inp2[return_value2])
	{
		return_value2++;
	}
	if (return_value1 > return_value2)
	{
		return (return_value2);
	}
	else
	{
		return (return_value1);
	}
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && i <= min_len(s1, s2))
	{
		if ((unsigned char)s1[i] == (unsigned char)s2[i])
		{
			i++;
			continue ;
		}
		if ((unsigned char)s1[i] > (unsigned char)s2[i])
		{
			return (1);
		}
		else
		{
			return (-1);
		}
	}
	return (0);
}
