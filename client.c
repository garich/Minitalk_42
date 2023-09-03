/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarijo- <agarijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 12:17:27 by agarijo-          #+#    #+#             */
/*   Updated: 2023/09/03 18:05:56 by agarijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "client.h"

void	leaks(void)
{
	system("leaks -q --list client");
}

void	ft_error(void)
{
	write(2, "error\n", 6);
	exit(1);
}

int	printbinofchar(char c, pid_t pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c & (1 << i)))
		{
			if (kill(pid, SIGUSR1) == -1)
				return (0);
			ft_putchar_fd('1', 1);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				return (0);
			ft_putchar_fd('0', 1);
		}
		i--;
		usleep(100);
	}
	ft_putchar_fd('\n', 1);
	return (1);
}

int	main(int argc, char **argv)
{
	int		i;
	pid_t	pid;

	if (argc != 3)
		ft_error();
	pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i])
	{
		if (!printbinofchar(argv[2][i], pid))
			ft_error();
		i++;
	}
	return (0);
}
