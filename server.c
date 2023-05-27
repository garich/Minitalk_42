/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarijo- <agarijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 11:05:42 by agarijo-          #+#    #+#             */
/*   Updated: 2023/05/27 14:02:30 by agarijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "server.h"

void	sighandler(int signum)
{
	static int				i;
	static unsigned char	c;

	i = 0;
	c = 0;
	if (signum == SIGINT)
	{
		ft_putstr_fd("\n", 1);
		ft_putstr_fd("Caught signal ", 1);
		ft_putnbr_fd(signum, 1);
		ft_putstr_fd(", coming out...", 1);
		ft_putstr_fd("\n", 1);
		exit(1);
	}
	else if (signum == SIGUSR1 || signum == SIGUSR2)
	{
		ft_putstr_fd("\n", 1);
		ft_putstr_fd("User signal ", 1);
		ft_putnbr_fd(signum, 1);
		ft_putstr_fd("\n", 1);
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
