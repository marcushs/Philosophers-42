/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:34:58 by hleung            #+#    #+#             */
/*   Updated: 2023/09/06 11:27:42 by hleung           ###   ########.fr       */
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
		if (pthread_create(data->threads + i, \
		NULL, &routine, &data->philos[i]) != 0)
		{
			pthread_mutex_unlock(&data->start);
			return (ft_putstr(ERR_THR), -1);
		}
		i++;
	}
	data->time_of_start = get_time();
	if (data->time_of_start == -1)
		return (-1);
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
		i++;
	}
	return (0);
}

void	*routine(void *philos)
{
	t_philo	*philo;

	philo = philos;
	pthread_mutex_lock(&philo->data->start);
	pthread_mutex_unlock(&philo->data->start);
	philo->last_eat = philo->data->time_of_start;
	if (philo->id % 2 == 0)
	{
		printf("%ld %d %s", get_time() - philo->data->time_of_start, \
		philo->id, THINK);
		usleep(50000);
	}
	else if (philo->id == philo->data->nb_philo \
	&& philo->data->nb_philo % 2 == 1 && philo->data->nb_philo > 1)
	{
		printf("%ld %d %s", get_time() - philo->data->time_of_start, \
		philo->id, THINK);
		usleep(1500);
	}
	if (simulation(philo) == -1)
		return (NULL);
	return (NULL);
}

int	simulation(t_philo *philo)
{
	while (philo->eat_count != philo->data->nb_eat)
	{
		if (take_fork(philo) == -1)
			return (-1);
		if (philo_eat(philo) == -1)
			return (-1);
		if (check_death(philo))
			return (-1);
		if (check_time_to_die(philo))
			return (-1);
		if (philo_sleep(philo) == -1)
			return (-1);
		if (check_death(philo))
			return (-1);
		if (check_time_to_die(philo))
			return (-1);
		if (philo_think(philo) == -1)
			return (-1);
		philo->eat_count++;
	}
	return (0);
}
