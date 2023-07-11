/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <minjeon2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:05:22 by minjeon2          #+#    #+#             */
/*   Updated: 2023/03/21 18:15:21 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	haystack_i;
	size_t	needle_i;

	haystack_i = 0;
	if (!*needle)
		return ((char *)haystack);
	if (haystack == needle)
		return ((char *)haystack);
	while (haystack_i < len && haystack[haystack_i])
	{
		needle_i = 0;
		while (haystack[haystack_i + needle_i] == needle[needle_i])
		{
			if (haystack[haystack_i + needle_i] == '\0' \
					|| needle[needle_i] == '\0')
				break ;
			if (haystack_i + needle_i >= len)
				return ((void *)0);
			needle_i++;
		}
		if (needle[needle_i] == '\0')
			return (&((char *)haystack)[haystack_i]);
		haystack_i++;
	}
	return ((void *)0);
}
