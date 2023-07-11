/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <minjeon2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:48:43 by minjeon2          #+#    #+#             */
/*   Updated: 2023/03/21 21:52:40 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_len;
	int		s2_len;
	int		return_value_i;
	int		s_i;
	char	*return_value;

	s_i = 0;
	return_value_i = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	return_value = (char *) malloc (sizeof (char) * (s1_len + s2_len) + 1);
	if (!return_value)
		return ((void *)0);
	while (return_value_i < s1_len)
		return_value[return_value_i++] = s1[s_i++];
	s_i = 0;
	while (return_value_i < s2_len + s1_len)
	{
		return_value[return_value_i] = s2[s_i];
		return_value_i++;
		s_i++;
	}
	return_value[return_value_i] = '\0';
	return (return_value);
}
