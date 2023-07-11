/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <minjeon2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 21:39:17 by minjeon2          #+#    #+#             */
/*   Updated: 2023/03/18 15:23:36 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*return_value;
	unsigned char	*unsigned_s;
	size_t			i;

	i = 0;
	return_value = (void *) 0;
	unsigned_s = (unsigned char *) s;
	while (i < n)
	{
		if (*unsigned_s == (unsigned char) c)
		{
			return_value = unsigned_s;
			break ;
		}
		i++;
		unsigned_s++;
	}
	return ((void *)return_value);
}
