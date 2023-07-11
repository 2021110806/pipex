/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <minjeon2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:43:52 by minjeon2          #+#    #+#             */
/*   Updated: 2023/03/18 17:13:13 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*unsigned_s1;
	unsigned char	*unsigned_s2;

	i = 0;
	unsigned_s1 = (unsigned char *) s1;
	unsigned_s2 = (unsigned char *) s2;
	while (i < n)
	{
		if (unsigned_s1[i] == unsigned_s2[i])
		{
			i++;
			continue ;
		}
		return (unsigned_s1[i] - unsigned_s2[i]);
	}
	return (0);
}
