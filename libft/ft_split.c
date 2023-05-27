/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarijo- <agarijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:22:12 by agarijo-          #+#    #+#             */
/*   Updated: 2023/03/24 15:26:29 by agarijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words_s(char const *s, char c)
{
	int	counter;
	int	amount;
	int	flag;

	amount = 0;
	counter = 0;
	flag = 0;
	while (*(s + counter))
	{
		if (*(s + counter) != c && flag != 1)
		{
			amount++;
			flag = 1;
		}
		else if (*(s + counter) == c)
			flag = 0;
		counter++;
	}
	return (amount);
}

static int	ft_size_word(const char *word, char c)
{
	int	counter;

	counter = 0;
	while (*(word + counter))
	{
		if (*(word + counter) == c)
			return (counter);
		counter++;
	}
	return (counter);
}

static char	*ft_ins_word(const char *s, int word_counter)
{
	int		counter;
	char	*word;

	counter = 0;
	word = malloc((word_counter + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (word_counter--)
	{
		*(word + counter) = *s++;
		counter++;
	}
	*(word + counter) = '\0';
	return (word);
}

void	free_memory(char **result_array)
{
	int	counter;

	counter = 0;
	while (result_array[counter])
	{
		free(result_array[counter]);
		result_array[counter] = NULL;
		counter ++;
	}
	free(result_array);
}

char	**ft_split(const char *s, char c)
{
	int		cr;
	int		flag;
	int		r_a_c;
	char	**r_a;

	cr = 0;
	flag = 0;
	r_a_c = 0;
	r_a = ft_calloc((ft_count_words_s(s, c) + 1), sizeof(char *));
	if (!r_a)
		return (NULL);
	while (*(s + cr))
	{
		if (*(s + cr) != c && flag != 1)
		{
			*(r_a + r_a_c) = ft_ins_word((s + cr), ft_size_word((s + cr), c));
			if (!*(r_a + r_a_c++))
				return (free_memory(r_a), NULL);
			flag = 1;
		}
		else if (*(s + cr) == c)
			flag = 0;
		cr++;
	}
	return (*(r_a + r_a_c) = NULL, r_a);
}
