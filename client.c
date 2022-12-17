/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 03:11:06 by msekhsou          #+#    #+#             */
/*   Updated: 2022/12/17 20:16:57 by msekhsou         ###   ########.fr       */
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
	int	bit;
	int	err;

	while (*str)
	{
		bit = 7;
		while (bit >= 0)
		{
			if ((*str >> bit & 1) == 1)
				err = kill(server_pid, SIGUSR1);
			else if ((*str >> bit & 1) == 0)
				err = kill(server_pid, SIGUSR2);
			if (err < 0)
			{
				write (2, "Invalid PID \n", 14);
				return ;
			}
			usleep(200);
			bit--;
		}
		str++;
	}
}

// void	binary(int pid, char *s)
// {
// 	int	i;
// 	int	bit;

// 	i = 0;
// 	if (!s)
// 		exit(1);
// 	while (1)
// 	{
// 		bit = -1;
// 		while (++bit < 9)
// 		{
// 			if (s[i] & (128 >> bit))
// 			{
// 				if (kill(pid, SIGUSR1) == -1)
// 					exit(1);
// 			}
// 			else
// 				if (kill(pid, SIGUSR2) == -1)
// 					exit(1);
// 			usleep(300);
// 		}
// 		if (!s[i])
// 		{
// 			write(1,"\n",1);
// 			break ;
// 		}
// 		i++;
// 	}
// }

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3 || av[2][0] == '\0')
	{
		write(1, "error\n", 6);
		exit(1);
	}
	pid = ft_atoi(av[1]);
	if (pid == -1)
	{
		write(1, "error\n", 6);
		exit(1);
	}
	ft_asci_to_bin(pid, av[2]);
	return (0);
}
