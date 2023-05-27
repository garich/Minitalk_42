/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_ps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarijo- <agarijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:38:41 by agarijo-          #+#    #+#             */
/*   Updated: 2023/04/28 16:50:49 by agarijo-         ###   ########.fr       */
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

int	ft_atoi_ps(const char *str, int *flag)
{
	int				sign;
	unsigned int	number;
	int				counter;

	number = 0;
	sign = ft_sign_and_spaces(str, &counter);
	while (str[counter] != '\0' && str[counter] >= 48 && str[counter] <= 57)
	{
		number = number * 10 + (str[counter] - '0');
		if (number > INT_MAX && sign == 1)
			return (*flag = 0, -1);
		if (number > INT_MIN && sign == -1)
			return (*flag = 0, 0);
		counter ++;
	}
	number = number * sign;
	return (number);
}
