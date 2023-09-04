/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:06:38 by hleung            #+#    #+#             */
/*   Updated: 2023/09/04 22:12:36 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int		fork_ready(t_fork *fork);

void	take_fork(t_philo *philo)
{
	while (!fork_ready(philo->l_fork))
		usleep(250);
	pthread_mutex_lock(&philo->l_fork->fork);
	philo->l_fork->is_locked = 1;
	pthread_mutex_unlock(&philo->l_fork->fork);
	while (!fork_ready(philo->r_fork))
		usleep(250);
	pthread_mutex_lock(&philo->r_fork->fork);
	philo->r_fork->is_locked = 1;
	pthread_mutex_unlock(&philo->r_fork->fork);
}

int	fork_ready(t_fork *fork)
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

void	eat(t_philo *philo)
{
	print_log(philo, FORK);
	print_log(philo, FORK);
	print_log(philo, EAT);
	ft_usleep(philo->data->time_to_eat);
	pthread_mutex_lock(&philo->l_fork->fork);
	philo->l_fork->is_locked = 0;
	pthread_mutex_unlock(&philo->l_fork->fork);
	pthread_mutex_lock(&philo->r_fork->fork);
	philo->r_fork->is_locked = 0;
	pthread_mutex_unlock(&philo->r_fork->fork);
}
