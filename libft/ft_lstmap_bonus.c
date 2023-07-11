/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <minjeon2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:49:19 by minjeon2          #+#    #+#             */
/*   Updated: 2023/03/28 16:32:02 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*return_value;
	t_list	*new_node;
	void	*f_content;

	return_value = 0;
	if (!lst || !f)
		return ((void *)0);
	while (lst)
	{
		f_content = f(lst -> content);
		new_node = ft_lstnew(f_content);
		if (!new_node)
		{
			del(f_content);
			ft_lstclear(&return_value, del);
			return ((void *)0);
		}
		ft_lstadd_back(&return_value, new_node);
		lst = lst -> next;
	}
	return (return_value);
}
