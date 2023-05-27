/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarijo- <agarijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:50:16 by agarijo-          #+#    #+#             */
/*   Updated: 2022/09/30 11:12:16 by agarijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size)
{
	unsigned int	offset;

	offset = 0;
	if (size > 0)
	{
		while (*(src + offset) != '\0' && (offset != size - 1))
		{
			*(dest + offset) = *(src + offset);
			offset++;
		}
		*(dest + offset) = '\0';
	}
	return (ft_strlen(src));
}
