/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 19:45:01 by hleung            #+#    #+#             */
/*   Updated: 2023/09/06 09:59:58 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	print_log(t_philo *philo, char *msg)
{
	suseconds_t	timestamp;

	if (check_death(philo))
		return (-1);
	if (check_time_to_die(philo))
		return (-1);
	pthread_mutex_lock(&philo->data->print);
	timestamp = get_time() - philo->data->time_of_start;
	printf("%ld %d %s", timestamp, philo->id, msg);
	pthread_mutex_unlock(&philo->data->print);
	return (0);
}
