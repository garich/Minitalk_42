/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarijo- <agarijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:37:32 by agarijo-          #+#    #+#             */
/*   Updated: 2022/11/02 18:57:34 by agarijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char				*cast_s;
	unsigned long		count;

	cast_s = s;
	count = 0;
	if (n != 0)
	{
		while (count <= n - 1)
		{
			*(cast_s + count) = '\0';
			count++;
		}
	}
}
