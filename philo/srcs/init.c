/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:53:24 by hleung            #+#    #+#             */
/*   Updated: 2023/08/31 11:23:38 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	data_init(int argc, char **argv, t_data *data)
{
	//int	i;
	
	data->philos = NULL;
	data->forks = NULL;
	if (parse(argc, argv, data) == -1)
		return (-1);
	data->philos = malloc(data->nb_philo * sizeof(t_philo));
	if (!data->philos)
		return (ft_putstr(MALLOC), -1);
	data->threads = malloc(data->nb_philo * sizeof(pthread_t));
	if (!data->threads)
		return (free_data(data), ft_putstr(MALLOC), -1);
	pthread_mutex_init(&data->start, NULL);
	data->forks = malloc(data->nb_philo * sizeof(pthread_mutex_t));
	if (!data->forks)
		return (free_data(data), ft_putstr(MALLOC), -1);
	// i = 0;
	// while (i < data->nb_philo)
	// {
	// 	pthread_mutex_init(data->forks + i, NULL);
	// 	i++;
	// }
	return (0);
}

void	philo_init(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		data->philos[i].id = i + 1;
		data->philos[i].data = data;
		i++;
	}
}

