/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarijo- <agarijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 20:41:56 by agarijo-          #+#    #+#             */
/*   Updated: 2022/11/02 19:47:54 by agarijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *needle, size_t len)
{
	size_t	needle_len;

	needle_len = ft_strlen(needle);
	if (!needle_len)
		return ((char *)hay);
	while ((*hay != '\0') && len)
	{
		if ((hay[0] == needle[0])
			&& (!ft_strncmp(hay, needle, needle_len))
			&& len >= needle_len)
			return ((char *)hay);
		hay++;
		len--;
	}
	return (0);
}
