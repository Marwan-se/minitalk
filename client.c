/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 03:11:06 by msekhsou          #+#    #+#             */
/*   Updated: 2022/12/17 04:48:27 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Minitalk.h"

// void	sft(int signum)
// {
// 	if (signum == SIGUSR1)
// 		ft_putstr("\nwell done\n");
// }

void	ft_asci_to_bin(pid_t server_pid, char *str)
{
	int	i;
	int	err;

	while (*str)
	{
		i = 7;
		while (i >= 0)
		{
			if ((*str >> i & 1) == 1)
				err = kill(server_pid, SIGUSR1);
			else if ((*str >> i & 1) == 0)
				err = kill(server_pid, SIGUSR2);
			if (err < 0)
			{
				write (2, "Invalid PID \n", 14);
				return ;
			}
			usleep(150);
			i--;
		}
		str++;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3 || av[2][0] == '\0')
	{
		write(1, "error\n", 6);
		exit(1);
	}
	signal(SIGUSR1, sft);
	pid = ft_atoi(av[1]);
	if (pid == -1)
	{
		write(1, "error\n", 6);
		exit(1);
	}
	ft_asci_to_bin(pid, av[2]);
}