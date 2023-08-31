/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:34:58 by hleung            #+#    #+#             */
/*   Updated: 2023/08/31 14:54:35 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine(void *philos);
int		simulation(t_philo *philo);

int	create_threads(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&data->start);
	while (i < data->nb_philo)
	{
		if (pthread_create(data->threads + i, NULL, &routine, &data->philos[i]) != 0)
			return (ft_putstr(ERR_THR), -1);
		i++;
	}
	data->time_of_start = get_time();
	if (data->time_of_start == -1)
		return (-1);
	printf("start time is %ld\n", data->time_of_start);
	pthread_mutex_unlock(&data->start);
	return (0);
}

int	join_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_join(data->threads[i], NULL) != 0)
			return (ft_putstr(ERR_JOIN), -1);
		printf("%ld thread[%d] finished execution\n", get_time() - data->time_of_start, i);
		i++;
	}
	return (0);
}

void	*routine(void *philos)
{
	t_philo *philo;

	philo = philos;
	pthread_mutex_lock(&philo->data->start);
	simulation(philo);
	pthread_mutex_unlock(&philo->data->start);
	return (NULL);
}

int	simulation(t_philo *philo)
{
	take_fork(philo);
	return (0);
}
