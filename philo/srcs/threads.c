/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:34:58 by hleung            #+#    #+#             */
/*   Updated: 2023/08/30 16:05:43 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine(void *philos);

int	create_threads(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&data->start);
	while (i < data->nb_philo)
	{
		if (pthread_create(data->threads + i, NULL, &routine, (void *)data->philos + i) != 0)
			return (ft_putstr(ERR_THR), -1);
		printf("Created thread[%d]\n", i);
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
		printf("Thread[%d] finished execution\n", i);
		i++;
	}
	return (0);
}

void	*routine(void *philos)
{
	t_philo *philo;

	philo = philos;
	pthread_mutex_lock(&philo->data->start);
	//simulation(data);
	// printf("Print from philo id: %d\n", id);
	printf("hi\n");
	pthread_mutex_unlock(&philo->data->start);
	return (NULL);
}

// int	simulation(t_data *data)
// {
// 	// take_fork(data);
// }
