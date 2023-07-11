/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <minjeon2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 23:21:30 by minjeon2          #+#    #+#             */
/*   Updated: 2023/05/23 16:28:21 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	min(size_t a, size_t b)
{
	if (a > b)
		return (b);
	return (a);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			return_value_i;
	size_t			s_i;
	size_t			total_len;
	char			*return_value;

	return_value_i = 0;
	s_i = start;
	total_len = 0;
	while (s[total_len])
		total_len++;
	if (total_len < start)
		return (ft_strdup(""));
	return_value = (char *) malloc (min(len, total_len - start) + 1);
	if (!return_value)
		return ((void *) 0);
	while (s[s_i] && (int)return_value_i < min(len, total_len - start))
	{
		return_value[return_value_i] = s[s_i];
		return_value_i++;
		s_i++;
	}
	return_value[return_value_i] = '\0';
	return (return_value);
}
