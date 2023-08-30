/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:53:24 by hleung            #+#    #+#             */
/*   Updated: 2023/08/29 15:30:07 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	data_init(int argc, char **argv, t_data *data)
{
	data->philos = NULL;
	data->forks = NULL;
	if (parse(argc, argv, data) == -1)
		return (-1);
	data->philos = malloc(data->parsed_args[0] * sizeof(t_philo));
	if (!data->philos)
		return (ft_putstr(MALLOC), -1);
	data->forks = malloc(data->parsed_args[0] * sizeof(pthread_mutex_t));
	if (!data->forks)
		return (free_data(data), ft_putstr(MALLOC), -1);
	return (0);
}

void	philo_init(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->parsed_args[0])
	{
		data->philos[i].id = i + 1;
		i++;
	}
}
