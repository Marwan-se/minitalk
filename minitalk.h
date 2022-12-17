/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 03:08:42 by msekhsou          #+#    #+#             */
/*   Updated: 2022/12/17 20:18:42 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include<stdio.h>
# include<string.h>
# include<unistd.h>
# include<stdlib.h>
# include<signal.h>

int		ft_atoi(const char *str);
void	ft_putstr(char *s);
void	ft_putchar(char c);
void	ft_putnbr(int n);

#endif