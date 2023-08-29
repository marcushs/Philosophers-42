/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 14:29:44 by hleung            #+#    #+#             */
/*   Updated: 2023/08/25 15:07:35 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int		ft_strlen(char *str);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
void	ft_putchar(int c);
void	print_log(int timestamp, int philo, char *action);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void	ft_putnbr(int nb)
{
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	print_log(int timestamp, int philo, char *action)
{
	ft_putnbr(timestamp);
	write(1, " ", 1);
	ft_putnbr(philo);
	write(1, " ", 1);
	ft_putstr(action);
}
