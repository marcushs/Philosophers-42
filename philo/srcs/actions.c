/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:06:38 by hleung            #+#    #+#             */
/*   Updated: 2023/09/04 21:15:27 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	take_fork(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->r_fork->fork);
		print_log(philo, FORK);
		pthread_mutex_lock(&philo->l_fork->fork);
		print_log(philo, FORK);
		eat(philo);
	}
	else
	{
		pthread_mutex_lock(&philo->l_fork->fork);
		print_log(philo, FORK);
		pthread_mutex_lock(&philo->r_fork->fork);
		print_log(philo, FORK);
		eat(philo);
	}
}

void	eat(t_philo *philo)
{
	print_log(philo, EAT);
	ft_usleep(philo->data->time_to_eat);
	pthread_mutex_unlock(&philo->l_fork->fork);
	pthread_mutex_unlock(&philo->r_fork->fork);
}
