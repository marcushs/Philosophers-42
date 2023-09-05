/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 19:45:01 by hleung            #+#    #+#             */
/*   Updated: 2023/09/05 14:02:58 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_log(t_philo *philo, char *msg)
{
	suseconds_t	timestamp;

	pthread_mutex_lock(&philo->data->print);
	timestamp = get_time() - philo->data->time_of_start;
	printf("%ld %d %s", timestamp, philo->id, msg);
	pthread_mutex_unlock(&philo->data->print);
}
