/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarijo- <agarijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 20:34:29 by agarijo-          #+#    #+#             */
/*   Updated: 2022/10/18 17:53:36 by agarijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_reverse(char *string)
{
	int		init;
	int		final;
	int		length;
	char	temp;

	init = 0;
	length = ft_strlen(string) - 1;
	final = length;
	temp = '\0';
	while (init <= (length / 2))
	{
		temp = *(string + init);
		*(string + init) = *(string + final);
		*(string + final) = temp;
		init++;
		final--;
	}
	return (string);
}

static char	*ft_to_char(int number, int size, int negative)
{
	char	*int_string;
	int		counter;

	counter = 0;
	if (negative == 0)
		int_string = malloc((size + 1) * sizeof(char));
	else
		int_string = malloc((size + 2) * sizeof(char));
	if (!int_string)
		return (0);
	while ((number / 10) > 0)
	{
		if (negative && number == 2147483647 && counter == 0)
			*(int_string + counter) = ((number % 10) + 1) + '0';
		else
			*(int_string + counter) = (number % 10) + '0';
		number = number / 10;
		counter++;
	}
	*(int_string + counter) = (number % 10) + '0';
	if (negative)
		*(int_string + ++counter) = '-';
	*(int_string + ++counter) = '\0';
	int_string = ft_reverse(int_string);
	return (int_string);
}

char	*ft_itoa(int n)
{
	int		negative;
	int		size;
	int		copy_number;

	negative = 0;
	size = 1;
	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
	{
		negative = 1;
		n = -n;
	}
	copy_number = n;
	while ((n / 10) != 0)
	{
		n = n / 10;
		size++;
	}
	if (copy_number == -2147483648)
		copy_number = 2147483647;
	return (ft_to_char(copy_number, size, negative));
}
