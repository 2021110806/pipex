/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <minjeon2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 21:28:41 by minjeon2          #+#    #+#             */
/*   Updated: 2023/03/21 21:03:25 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char			*return_value;
	unsigned long	i;

	i = 0;
	return_value = (char *) malloc (sizeof (char) * count * size);
	if (!return_value)
		return ((void *)0);
	while (i < count * size)
		return_value[i++] = 0;
	return ((void *)return_value);
}
