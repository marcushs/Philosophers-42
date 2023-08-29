/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 14:51:45 by hleung            #+#    #+#             */
/*   Updated: 2023/08/29 11:10:45 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_isdigit(int c);
int	check_format(char *str);
int	ft_atoi(char *str);

int	parse(char **argv, t_data *data)
{
	int	i;

	i = 1;
	while (i <= 4)
	{
		if (check_format(argv[i]) == -1)
			return (-1);
		data->parsed_times[i - 1] = ft_atoi(argv[i]);
		if (data->parsed_times[i - 1] == -1)
			return (ft_putstr(LIM), -1);
		i++;
	}
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