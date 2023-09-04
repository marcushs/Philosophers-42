/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:53:24 by hleung            #+#    #+#             */
/*   Updated: 2023/09/04 20:15:02 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	data_init(int argc, char **argv, t_data *data)
{
	int	i;

	data->philos = NULL;
	if (parse(argc, argv, data) == -1)
		return (-1);
	data->is_dead = 0;
	data->philos = malloc(data->nb_philo * sizeof(t_philo));
	if (!data->philos)
		return (ft_putstr(MALLOC), -1);
	data->threads = malloc(data->nb_philo * sizeof(pthread_t));
	if (!data->threads)
		return (free_data(data), ft_putstr(MALLOC), -1);
	data->forks = malloc(data->nb_philo * sizeof(t_fork));
	if (!data->forks)
		return (free_data(data), ft_putstr(MALLOC), -1);
	i = -1;
	while (++i < data->nb_philo)
	{
		pthread_mutex_init(&data->forks[i].fork, NULL);
		//printf("data->forks[%d].fork has address %p\n", i, &data->forks[i].fork);
		data->forks[i].is_locked = 0;
	}
	pthread_mutex_init(&data->start, NULL);
	pthread_mutex_init(&data->print, NULL);
	return (0);
}

void	philo_init(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		data->philos[i].id = i + 1;
		data->philos[i].last_eat = 0;
		data->philos[i].eat_count = 0;
		if (i == data->nb_philo - 1)
		{
			data->philos[i].l_fork = &data->forks[0];
			data->philos[i].r_fork = &data->forks[i];
		}
		else
		{
			data->philos[i].l_fork = &data->forks[i + 1];
			data->philos[i].r_fork = &data->forks[i];
		}
		pthread_mutex_init(&data->philos[i].eat_lock, NULL);
		data->philos[i].data = data;
		i++;
	}
}

