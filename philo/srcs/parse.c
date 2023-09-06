/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 14:51:45 by hleung            #+#    #+#             */
/*   Updated: 2023/09/06 14:18:08 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_isdigit(int c);
int	check_format(char *str);
int	ft_atoi(char *str);

int	parse(int argc, char **argv, t_data *data)
{
	int	i;
	int	arr[5];

	i = 1;
	while (i < argc)
	{
		if (check_format(argv[i]) == -1)
			return (-1);
		arr[i - 1] = ft_atoi(argv[i]);
		if (arr[i - 1] == -1)
			return (ft_putstr(LIM), -1);
		i++;
	}
	data->nb_philo = arr[0];
	data->time_to_die = arr[1];
	data->time_to_eat = arr[2];
	data->time_to_sleep = arr[3];
	if (argc == 6)
		data->nb_eat = arr[4];
	else
		data->nb_eat = -1;
	return (0);
}

int	check_format(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) || ((str[i]) == '+' && i) || i > 9)
			return (ft_putstr(INV_FORM), -1);
		i++;
	}
	return (0);
}

int	ft_isdigit(int c)
{
	return ((c >= '0' && c <= '9') || c == '+');
}

int	ft_atoi(char *str)
{
	long	res;
	int		i;

	res = 0;
	i = 0;
	while (str[i])
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	if (res > INT_MAX)
		return (-1);
	return ((int)res);
}
