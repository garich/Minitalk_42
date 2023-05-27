/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarijo- <agarijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 12:22:44 by agarijo-          #+#    #+#             */
/*   Updated: 2023/05/27 13:21:32 by agarijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H
# include <signal.h>

void	error(void);

// It's a bit shift operation. For every 1 on the right,
// you can think of yourself as multiplying the value on the left by 2.
// So, 2 << 1 = 4 and 2 << 2 = 8. This is much more efficient than doing 1 * 2.
int		printbincharpad(char c, pid_t pid);

#endif
