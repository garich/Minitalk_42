/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarijo- <agarijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:38:05 by agarijo-          #+#    #+#             */
/*   Updated: 2022/11/03 19:08:10 by agarijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_includes(const char *set, char c)
{
	while (*set)
		if (*set++ == c)
			return (0);
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start_index;
	int		end_index;
	char	*result;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start_index = 0;
	end_index = ft_strlen(s1);
	while (ft_includes(set, s1[start_index]) == 0)
		start_index++;
	if (start_index == ft_strlen(s1))
		return (ft_strdup(""));
	while (ft_includes(set, s1[end_index - 1]) == 0)
		end_index--;
	result = ft_substr(s1, start_index, end_index - start_index);
	return (result);
}
