/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarijo- <agarijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 11:20:24 by agarijo-          #+#    #+#             */
/*   Updated: 2022/11/02 18:51:21 by agarijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	cast_c;
	unsigned long	counter;
	char			*cast_b;

	counter = 0;
	cast_c = (unsigned char) c;
	cast_b = (char *)b;
	while (len != 0 && counter <= len - 1)
	{
		*(cast_b + counter) = cast_c;
		counter++;
	}
	return (cast_b);
}
