/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <minjeon2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:35:02 by minjeon2          #+#    #+#             */
/*   Updated: 2023/03/24 17:11:30 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*return_value;
	int		i;

	i = 0;
	while (s[i])
		i++;
	return_value = (char *)s;
	while (i > 0)
	{
		if (return_value[i] == (char)c)
			return (&return_value[i]);
		i--;
	}
	if (return_value[i] == (char)c)
		return (&return_value[i]);
	return ((void *)0);
}
/*
#include <stdio.h>
int main(void)
{
printf("%s\n",ft_strrchr("teste", 'e'));
}*/
