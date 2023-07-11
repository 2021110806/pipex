/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <minjeon2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:43:26 by minjeon2          #+#    #+#             */
/*   Updated: 2023/03/21 21:30:42 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*return_value;

	return_value = (unsigned char *) b;
	i = 0;
	while (i < len)
	{
		return_value[i] = (unsigned char) c;
		i++;
	}
	return ((void *) return_value);
}
