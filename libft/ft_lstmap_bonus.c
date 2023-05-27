/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarijo- <agarijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:32:06 by agarijo-          #+#    #+#             */
/*   Updated: 2023/03/24 15:13:44 by agarijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*move;

	if (!lst)
		return (NULL);
	new = ft_lstnew(f(lst->content));
	move = new;
	lst = lst->next;
	while (lst)
	{
		move->next = ft_lstnew(f(lst->content));
		if (!move->next)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		move = move->next;
		lst = lst->next;
	}
	move->next = NULL;
	return (new);
}
