/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarijo- <agarijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 19:50:40 by agarijo-          #+#    #+#             */
/*   Updated: 2022/09/28 13:15:04 by agarijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned char	c;
	unsigned char	*s1s;
	unsigned char	*s2s;

	c = 0;
	s1s = (unsigned char *) s1;
	s2s = (unsigned char *) s2;
	while ((s1s[c] != '\0' || s2s[c] != '\0') && c < n)
	{
		if (s1s[c] > s2s[c])
		{
			return (1);
		}
		else if (s1s[c] < s2s[c])
		{
			return (-1);
		}
		c++;
	}
	return (0);
}
