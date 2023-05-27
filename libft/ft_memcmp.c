/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarijo- <agarijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 17:26:04 by agarijo-          #+#    #+#             */
/*   Updated: 2022/10/01 20:33:57 by agarijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*s_s1;
	unsigned const char	*s_s2;

	s_s1 = (unsigned const char *)s1;
	s_s2 = (unsigned const char *)s2;
	if ((!s_s1 && !s_s2) || (s_s1 == s_s2))
		return (0);
	while (n)
	{
		if (*(s_s1++) != *(s_s2++))
			return (s_s1[-1] - s_s2[-1]);
		n--;
	}
	return (0);
}
