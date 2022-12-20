/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:58:36 by msekhsou          #+#    #+#             */
/*   Updated: 2022/12/20 20:33:37 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk_bonus.h"

void	msg_done(int signum)
{
	if (signum == SIGUSR1)
		ft_putstr("\nwell done\n");
}

void	binary(int pid, char *s)
{
	int	i;
	int	bit;

	i = 0;
	if (!s)
		exit(1);
	while (1)
	{
		bit = -1;
		while (++bit < 9)
		{
			if (s[i] & (128 >> bit))
			{
				if (kill(pid, SIGUSR1) == -1)
					exit(1);
			}
			else
				if (kill(pid, SIGUSR2) == -1)
					exit(1);
			usleep(300);
		}
		if (!s[i])
			break ;
		i++;
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
	signal(SIGUSR1, msg_done);
	pid = ft_atoi(av[1]);
	if (pid == -1)
	{
		write(1, "error\n", 6);
		exit(1);
	}
	binary(pid, av[2]);
	return (0);
}
