/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 03:11:54 by msekhsou          #+#    #+#             */
/*   Updated: 2022/12/17 03:34:10 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

void	ft_bintoasc(int sig)
{
	static char	c;
	static int	bit;

	if (sig == SIGUSR1)
		c |= 1;
	bit++;
	if (bit == 8)
	{
		write (1, &c, 1);
		bit = 0;
		c = 0;
	}
	c = c << 1;
}

int main(void)
{
	pid_t	pid;

	signal(SIGUSR1, &ft_bintoasc);
	signal(SIGUSR2, &ft_bintoasc);
	pid = getpid();
	ft_putstr("PID : ");
	ft_putnbr(pid);
	ft_putchar('\n');
	while (1)
		pause();
	return (0);
}
