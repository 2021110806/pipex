/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <minjeon2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:40:14 by minjeon2          #+#    #+#             */
/*   Updated: 2023/03/21 21:31:39 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*return_value;
	int		return_value_i;
	int		s_i;

	s_i = 0;
	return_value_i = 0;
	return_value = (char *) malloc
		(sizeof (char) * (ft_strlen((char *) s) + 1));
	if (!return_value)
		return ((void *)0);
	while (s[s_i])
	{
		return_value[return_value_i] = f(s_i, s[s_i]);
		s_i++;
		return_value_i++;
	}
	return_value[return_value_i] = '\0';
	return (return_value);
}
