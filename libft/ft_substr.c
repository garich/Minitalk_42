/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarijo- <agarijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:23:13 by agarijo-          #+#    #+#             */
/*   Updated: 2022/11/03 18:06:06 by agarijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub_string;
	int				count;
	unsigned int	len_s;

	count = 0;
	len_s = ft_strlen(s);
	if (start >= len_s || len_s == 0)
		return (ft_strdup(""));
	if (len > len_s)
		len = len_s;
	if (len > (len_s - (int)start))
		len = len_s - (int)start;
	sub_string = (char *)malloc((len + 1) * sizeof(char));
	if (!sub_string)
		return (NULL);
	while (len && *(s + start + count))
	{
		*(sub_string + count) = *(s + start + count);
		len--;
		count++;
	}
	*(sub_string + count) = '\0';
	return (sub_string);
}
