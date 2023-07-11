/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <minjeon2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:35:29 by minjeon2          #+#    #+#             */
/*   Updated: 2023/05/23 16:23:57 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;
	char	*ret;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (s1[len])
		len++;
	copy = (char *) malloc (len * sizeof (char) + 1);
	if (!copy)
		return ((void *)0);
	ret = copy;
	i = 0;
	while (*s1)
	{
		*copy = *s1;
		copy++;
		s1++;
	}
	*copy = '\0';
	return (ret);
}
