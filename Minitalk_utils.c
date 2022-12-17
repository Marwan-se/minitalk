/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 03:11:34 by msekhsou          #+#    #+#             */
/*   Updated: 2022/12/17 20:19:06 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

int	ft_atoi(const char *str)
{
	int	x;
	int	sign;
	int	res;

	x = 0;
	res = 0;
	sign = 1;
	while (str[x] == 32 || (str[x] >= 9 && str[x] <= 13))
		x++;
	if (str[x] == '-')
	{
		sign = -1;
		x++;
	}
	else if (str[x] == '+')
		x++;
	while (str[x] != '\0' && str[x] >= '0' && str[x] <= '9')
	{
		res *= 10;
		res += str[x] - 48;
		x++;
	}
	return (res * sign);
}

void	ft_putstr(char *s)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write (1, &s[i], 1);
		i++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		n = 8;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + 48);
}
