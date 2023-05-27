/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarijo- <agarijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 18:59:53 by agarijo-          #+#    #+#             */
/*   Updated: 2022/10/01 16:31:24 by agarijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	count;

	count = ft_strlen(s);
	if (c == '\0')
		return ((char *)(s + count));
	while ((*(s + count) != (char) c) && count > 0)
		count --;
	if ((*(s + count) != (char) c))
		return (NULL);
	return ((char *)s + count);
}
