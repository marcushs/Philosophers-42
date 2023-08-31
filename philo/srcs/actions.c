/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:06:38 by hleung            #+#    #+#             */
/*   Updated: 2023/08/31 15:28:03 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	take_fork(t_philo *philo)
{
	//pthread_mutex_lock(&philo->data->forks[philo->id]);
	pthread_mutex_lock(&philo->data->forks[philo->id - 1]);
	//printf("%ld %d has taken a fork %d\n", get_time() - philo->data->time_of_start, philo->id, philo->l_fork);
	printf("%ld %d has taken a fork %d\n", get_time() - philo->data->time_of_start, philo->id, philo->r_fork);
	//printf("%ld %d is eating\n", get_time() - philo->data->time_of_start, philo->id);
	usleep(philo->data->time_to_eat * 1000);
	//pthread_mutex_unlock(&philo->data->forks[philo->l_fork]);
	pthread_mutex_unlock(&philo->data->forks[philo->r_fork]);
	return (0);
}

