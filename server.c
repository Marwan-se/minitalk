/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 03:11:54 by msekhsou          #+#    #+#             */
/*   Updated: 2022/12/20 20:32:07 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

void	ft_bintoasc(int signum, siginfo_t *info, void *context)
{
	static int	g_pid = 0;
	static char	c = 0xFF;
	static int	bit = 0;	

	(void) context;
	if (g_pid != info->si_pid)
	{
		c = 0xFF;
		bit = 0;
		g_pid = info->si_pid;
	}
	if (signum == SIGUSR1)
	{
		c |= 0x80 >> bit;
	}
	else if (signum == SIGUSR2)
	{
		c ^= 0x80 >> bit;
	}
	if (bit++ == 8)
	{
		ft_putchar(c);
		bit = 0;
		c = 0xFF;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = ft_bintoasc;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putstr("PID : ");
	ft_putnbr(getpid());
	ft_putchar('\n');
	while (1)
		pause();
	return (0);
}
