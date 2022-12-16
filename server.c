/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 21:10:52 by msekhsou          #+#    #+#             */
/*   Updated: 2022/12/16 10:44:00 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

void	bin_to_asci(int signum, siginfo_t *info, void *context)
{
	static int	g_pid = 0;
	static char	c = 0xFF;
	static int	bit = 0;	

	(void) context;
	// if (g_pid != info->si_pid)
	// {
	// 	c = 0;
	// 	bit = 0;
	// 	g_pid = info->si_pid;
	// }
	if (signum == SIGUSR1)
		c |= 0x80 >> bit;
	if (signum == SIGUSR2)
		c ^= 0x80 >> bit; 
	if (bit++ == 8)
	{
		ft_putchar(c);
		bit = 0;
		c = 0xFF;
	}
}

int main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = bin_to_asci;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putstr("PID : ");
	ft_putnbr(getpid());
	ft_putchar('\n');
	while (1)
		pause();
}
