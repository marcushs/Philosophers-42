/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:06:38 by hleung            #+#    #+#             */
/*   Updated: 2023/09/06 09:59:42 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

inline int	philo_sleep(t_philo *philo)
{
	if (check_death(philo))
		return (-1);
	if (check_time_to_die(philo))
		return (-1);
	if (print_log(philo, SLEEP) == -1)
		return (-1);
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
	if (print_log(philo, THINK) == -1)
		return (-1);
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
