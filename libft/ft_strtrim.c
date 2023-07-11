/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <minjeon2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 15:21:31 by minjeon2          #+#    #+#             */
/*   Updated: 2023/03/21 21:34:17 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	len(char const *s)
{
	int	return_value;

	return_value = 0;
	while (s[return_value])
		return_value++;
	return (return_value);
}

static int	is_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		return_value_i;
	int		start;
	int		end;
	char	*return_value;

	return_value_i = 0;
	start = 0;
	end = len(s1) - 1;
	return_value_i = 0;
	while (is_in_set(s1[start], set))
		start++;
	while (start < end && is_in_set(s1[end], set))
		end--;
	return_value = (char *)malloc(end - start + 2);
	if (!return_value)
		return ((void *) 0);
	while (start < end + 1)
	{
		return_value[return_value_i] = s1[start];
		start++;
		return_value_i++;
	}
	return_value[return_value_i] = '\0';
	return (return_value);
}
