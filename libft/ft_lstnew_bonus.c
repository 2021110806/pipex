/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <minjeon2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:48:34 by minjeon2          #+#    #+#             */
/*   Updated: 2023/03/28 16:10:53 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc (sizeof (t_list));
	if (!new_node)
		return ((void *)0);
	new_node -> content = content;
	new_node -> next = (void *)0;
	return (new_node);
}
