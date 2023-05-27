/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarijo- <agarijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 12:44:09 by agarijo-          #+#    #+#             */
/*   Updated: 2022/10/09 00:07:41 by agarijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_sign_and_spaces(const char *str, int *p_counter)
{
	int	sign;
	int	counter;

	counter = 0;
	sign = 1;
	while ((str[counter] >= 9 && str[counter] <= 13) || str[counter] == 32)
	{
		counter++;
	}
	if (str[counter] == 43 || str[counter] == 45)
	{
		if (str[counter] == 45)
			sign = sign * -1;
		counter++;
	}
	*p_counter = counter;
	return (sign);
}

int	ft_atoi(const char *str)
{
	int						sign;
	unsigned long int		number;
	int						counter;

	number = 0;
	sign = ft_sign_and_spaces(str, &counter);
	while (str[counter] != '\0' && str[counter] >= 48 && str[counter] <= 57)
	{
		if (number >= 9223372036854775807 && sign == 1)
			return (-1);
		if (number > 9223372036854775807 && sign == -1)
			return (0);
		number = number * 10 + (str[counter] - '0');
		counter ++;
	}
	number = number * sign;
	return (number);
}
