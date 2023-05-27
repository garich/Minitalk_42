/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarijo- <agarijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:13:53 by agarijo-          #+#    #+#             */
/*   Updated: 2022/11/02 18:57:39 by agarijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*p_dest;
	unsigned const char	*p_source;

	p_dest = (unsigned char *)dst;
	p_source = (unsigned const char *)src;
	if (!dst && !src)
		return (0);
	while (n)
	{
		*(p_dest++) = *(p_source++);
		--n;
	}
	return (dst);
}
