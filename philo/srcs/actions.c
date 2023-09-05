/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:06:38 by hleung            #+#    #+#             */
/*   Updated: 2023/09/05 14:54:24 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int		fork_ready(t_fork *fork);

inline int	take_fork(t_philo *philo)
{
	if (check_death(philo))
		return (-1);
	if (check_time_to_die(philo))
		return (-1);
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
	return (1);
}

inline int	fork_ready(t_fork *fork)
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

inline int	philo_eat(t_philo *philo)
{
	if (check_death(philo))
		return (-1);
	if (philo->eat_count != 0)
		if (check_time_to_die(philo))
			return (-1);
	philo->last_eat = get_time();
	if (check_time_to_die(philo))
		return (-1);
	if (check_death(philo))
		return (-1);
	print_log(philo, FORK);
	print_log(philo, FORK);
	print_log(philo, EAT);
	if (ft_usleep(philo, philo->last_eat + philo->data->time_to_eat) == -1)
		return (-1);
	pthread_mutex_lock(&philo->l_fork->fork);
	philo->l_fork->is_locked = 0;
	pthread_mutex_unlock(&philo->l_fork->fork);
	pthread_mutex_lock(&philo->r_fork->fork);
	philo->r_fork->is_locked = 0;
	pthread_mutex_unlock(&philo->r_fork->fork);
	return (1);
}

inline int	philo_sleep(t_philo *philo)
{
	if (check_death(philo))
		return (-1);
	if (check_time_to_die(philo))
		return (-1);
	print_log(philo, SLEEP);
	if (ft_usleep(philo, philo->data->time_to_sleep) == -1)
		return (-1);
	return (1);
}

inline int	philo_think(t_philo *philo)
{
	if (check_death(philo))
		return (-1);
	if (check_time_to_die(philo))
		return (-1);
	print_log(philo, THINK);
	return (1);
}

inline int	check_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->died);
	if (philo->data->death == 1)
	{
		pthread_mutex_unlock(&philo->data->died);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->died);
	return (0);
}

inline int	check_time_to_die(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->died);
	if (get_time() - philo->last_eat >= philo->data->time_to_die && philo->data->death == 0)
	{
		print_log(philo, DIE);
		philo->data->death = 1;
		pthread_mutex_unlock(&philo->data->died);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->died);
	return (0);
}
