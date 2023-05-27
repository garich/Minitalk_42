/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarijo- <agarijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:48:47 by agarijo-          #+#    #+#             */
/*   Updated: 2022/10/08 23:49:06 by agarijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, const char *src, unsigned int size)
{
	unsigned int	c_src;
	unsigned int	c_dest;
	unsigned int	t_src;
	unsigned int	t_dest;

	t_src = ft_strlen(src);
	if (size == 0)
		return (t_src);
	t_dest = ft_strlen(dest);
	c_src = 0;
	c_dest = t_dest;
	if (size <= t_dest)
		return (t_src + size);
	while (src[c_src] != '\0' && c_src < size - t_dest - 1)
	{
		dest[c_dest] = src[c_src];
		c_src++;
		c_dest++;
	}
	dest[c_dest] = '\0';
	return (t_src + t_dest);
}
