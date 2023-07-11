/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <minjeon2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:50:29 by minjeon2          #+#    #+#             */
/*   Updated: 2023/03/27 19:50:31 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr;

	if (!(*lst) || !del)
		return ;
	while (*lst)
	{
		curr = (*lst)-> next;
		del((*lst)-> content);
		free(*lst);
		*lst = curr;
	}
}
