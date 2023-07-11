/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <minjeon2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:32:21 by minjeon2          #+#    #+#             */
/*   Updated: 2023/03/21 21:52:06 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	*return_value;
	char	*char_s;

	char_s = (char *) s;
	return_value = (void *) 0;
	while (*char_s != '\0')
	{
		if (*char_s == (char)c)
		{
			return_value = char_s;
			break ;
		}
		char_s++;
	}
	if ((char)c == 0)
		return (char_s);
	return (return_value);
}
