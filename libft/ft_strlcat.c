/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <minjeon2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 20:26:57 by minjeon2          #+#    #+#             */
/*   Updated: 2023/03/16 21:16:48 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	find_return_value(char *dest, char *src, size_t size)
{
	unsigned int	dest_size;
	unsigned int	src_size;

	dest_size = 0;
	src_size = 0;
	while (*dest)
	{
		dest_size++;
		dest++;
	}
	while (*src)
	{
		src_size++;
		src++;
	}
	if (size < dest_size)
	{
		return (src_size + size);
	}
	return (dest_size + src_size);
}

unsigned int	ft_strlcat(char *dest, char *src, size_t size)
{
	unsigned int	dest_ind;
	unsigned int	src_ind;
	unsigned int	return_value;

	dest_ind = 0;
	src_ind = 0;
	return_value = find_return_value(dest, src, size);
	while (dest[dest_ind] != '\0')
	{
		dest_ind++;
	}
	while (dest_ind + 1 < size && src[src_ind])
	{
		dest[dest_ind] = src[src_ind];
		dest_ind++;
		src_ind++;
	}
	dest[dest_ind] = '\0';
	return (return_value);
}
