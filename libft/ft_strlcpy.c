/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <minjeon2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:07:53 by minjeon2          #+#    #+#             */
/*   Updated: 2023/03/18 15:45:31 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

unsigned int	ft_strlcpy(char *dest, char *src, size_t size)
{
	unsigned int	src_len;
	unsigned int	i;

	i = 0;
	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	while (i < src_len && i + 1 < size)
	{
		dest[i] = src[i];
		i++;
	}
	if (size != 0)
		dest[i] = '\0';
	return (src_len);
}
