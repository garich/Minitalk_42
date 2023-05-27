/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarijo- <agarijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 18:10:43 by agarijo-          #+#    #+#             */
/*   Updated: 2022/11/06 13:27:26 by agarijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*first;
	t_list	*next;

	first = *lst;
	while (first)
	{
		next = first->next;
		ft_lstdelone(first, del);
		first = next;
	}
	*lst = NULL;
}
