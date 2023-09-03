/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarijo- <agarijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 11:05:42 by agarijo-          #+#    #+#             */
/*   Updated: 2023/09/03 18:05:51 by agarijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "server.h"

char	g_c[8];

void	leaks(void)
{
	system("leaks -q --list server");
}

int	power(int base, int exponent)
{
	int	result;
	int	counter;

	counter = 0;
	result = 1;
	while (counter++ < exponent)
		result *= base;
	return (result);
}

int	printcharofbin(char *c)
{
	int	i;
	int	ascii;

	ascii = 0;
	i = 0;
	while (c[i])
	{
		if (c[i] == 49)
			ascii += power(2, (7 - i));
		i++;
	}
	ft_putchar_fd(ascii, 1);
	return (1);
}

void	sighandler(int signum)
{
	static int	i = 0;

	if (signum == SIGINT)
	{
		ft_putstr_fd("\n", 1);
		ft_putstr_fd("Caught signal ", 1);
		ft_putnbr_fd(signum, 1);
		ft_putstr_fd(", coming out...", 1);
		ft_putstr_fd("\n", 1);
		exit(0);
	}
	else if (signum == SIGUSR1)
		g_c[i] = '1';
	else if (signum == SIGUSR2)
		g_c[i] = '0';
	i++;
	if (i == 8)
	{
		i = 0;
		printcharofbin(g_c);
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putstr_fd("pid: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n", 1);
	while (1)
	{
		signal(SIGINT, sighandler);
		signal(SIGUSR1, sighandler);
		signal(SIGUSR2, sighandler);
		pause();
	}
	return (0);
}
