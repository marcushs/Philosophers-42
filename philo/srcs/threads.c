/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:34:58 by hleung            #+#    #+#             */
/*   Updated: 2023/09/04 21:44:58 by hleung           ###   ########.fr       */
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
		//printf("created thread[%d]\n", i);
		i++;
	}
	data->time_of_start = get_time();
	if (data->time_of_start == -1)
		return (-1);
	//printf("start time is %ld\n", data->time_of_start);
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
		//printf("%ld thread[%d] finished execution\n", get_time() - data->time_of_start, i);
		i++;
	}
	return (0);
}

void	*routine(void *philos)
{
	t_philo *philo;

	philo = philos;
	pthread_mutex_lock(&philo->data->start);
	pthread_mutex_unlock(&philo->data->start);
	simulation(philo);
	// print_log(philo, "hi\n");
	// ft_usleep(300);
	return (NULL);
}

int	simulation(t_philo *philo)
{
	// while (philo->eat_count != philo->data->nb_eat)
	// {
		
	// }
	if (philo->id % 2 == 0)
	{
		print_log(philo, THINK);
		ft_usleep(200);
	}
	else if (philo->id == philo->data->nb_philo && philo->data->nb_philo % 2 == 1)
	{
		print_log(philo, THINK);
		ft_usleep(200);
	}
	take_fork(philo);
	eat(philo);
	// printf("Thread[%d] has left fork %p\n", philo->id, philo->l_fork);
	// printf("Thread[%d] has right fork %p\n", philo->id, philo->r_fork);
	return (0);
}
