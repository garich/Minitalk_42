/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarijo- <agarijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:15:47 by agarijo-          #+#    #+#             */
/*   Updated: 2022/11/03 18:48:57 by agarijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	int		length_string;
	int		counter;

	counter = 0;
	length_string = ft_strlen(s1) + ft_strlen(s2);
	string = malloc((1 + length_string) * sizeof(char));
	if (!string)
		return (NULL);
	while (*s1 != '\0')
		*(string + counter++) = *s1++;
	while (*s2 != '\0')
		*(string + counter++) = *s2++;
	*(string + counter) = '\0';
	return (string);
}
