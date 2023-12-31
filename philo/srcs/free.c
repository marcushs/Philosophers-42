/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:30:23 by hleung            #+#    #+#             */
/*   Updated: 2023/09/06 19:07:41 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	free_and_null(void	**arr)
{
	free(*arr);
	*arr = NULL;
}

void	free_data(t_data *data)
{
	int	i;

	if (data->philos)
	{
		i = -1;
		while (++i < data->nb_philo)
			pthread_mutex_destroy(&data->philos[i].eat_lock);
		free_and_null((void *)&data->philos);
	}
	if (data->threads)
		free_and_null((void *)&data->threads);
	if (data->forks)
	{
		i = -1;
		while (++i < data->nb_philo)
			pthread_mutex_destroy(&data->forks[i].fork);
		free_and_null((void *)&data->forks);
	}
	pthread_mutex_destroy(&data->start);
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->died);
}
