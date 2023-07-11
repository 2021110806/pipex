/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <minjeon2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:35:34 by minjeon2          #+#    #+#             */
/*   Updated: 2023/03/21 21:02:33 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	cp_memset(void *b, int c, size_t len)
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
}

void	ft_bzero(void *s, size_t n)
{
	cp_memset(s, 0, n);
}
