/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 09:54:36 by hleung            #+#    #+#             */
/*   Updated: 2023/09/06 11:20:22 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static inline int	take_left_fork(t_philo *philo);
static inline int	take_right_fork(t_philo *philo);
static inline int	fork_ready(t_fork *fork);

inline int	philo_eat(t_philo *philo)
{
	if (check_death(philo))
		return (-1);
	if (philo->eat_count != 0)
		if (check_time_to_die(philo))
			return (-1);
	philo->last_eat = get_time();
	if (check_death(philo))
		return (-1);
	if (check_time_to_die(philo))
		return (-1);
	if (print_log(philo, FORK) == -1)
		return (-1);
	if (print_log(philo, FORK) == -1)
		return (-1);
	if (print_log(philo, EAT) == -1)
		return (-1);
	if (ft_usleep(philo, philo->data->time_to_eat) == -1)
		return (-1);
	pthread_mutex_lock(&philo->l_fork->fork);
	philo->l_fork->is_locked = 0;
	pthread_mutex_unlock(&philo->l_fork->fork);
	pthread_mutex_lock(&philo->r_fork->fork);
	philo->r_fork->is_locked = 0;
	pthread_mutex_unlock(&philo->r_fork->fork);
	return (1);
}

inline int	take_fork(t_philo *philo)
{
	if (check_death(philo))
		return (-1);
	if (check_time_to_die(philo))
		return (-1);
	if (take_left_fork(philo) == -1)
		return (-1);
	if (take_right_fork(philo) == -1)
		return (-1);
	return (1);
}

static inline int	take_left_fork(t_philo *philo)
{
	while (!fork_ready(philo->l_fork))
	{
		if (check_death(philo))
			return (-1);
		if (check_time_to_die(philo))
			return (-1);
		usleep(250);
	}
	pthread_mutex_lock(&philo->l_fork->fork);
	philo->l_fork->is_locked = 1;
	pthread_mutex_unlock(&philo->l_fork->fork);
	return (0);
}

static inline int	take_right_fork(t_philo *philo)
{
	while (!fork_ready(philo->r_fork))
	{
		if (check_death(philo))
			return (-1);
		if (check_time_to_die(philo))
			return (-1);
		usleep(250);
	}
	pthread_mutex_lock(&philo->r_fork->fork);
	philo->r_fork->is_locked = 1;
	pthread_mutex_unlock(&philo->r_fork->fork);
	return (0);
}

static inline int	fork_ready(t_fork *fork)
{
	pthread_mutex_lock(&fork->fork);
	if (fork->is_locked)
	{
		pthread_mutex_unlock(&fork->fork);
		return (0);
	}
	pthread_mutex_unlock(&fork->fork);
	return (1);
}
