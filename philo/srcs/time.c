/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:53:20 by hleung            #+#    #+#             */
/*   Updated: 2023/09/05 13:22:11 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

suseconds_t	get_time(void)
{
	struct timeval tv;

	if (gettimeofday(&tv, NULL) == -1)
		return (ft_putstr(GET_TIME), -1);
	return (tv.tv_sec * (suseconds_t)1000 + tv.tv_usec * 0.001);
}

int	ft_usleep(t_philo *philo, int ms)
{
	suseconds_t	time;

	time = get_time();
	while (get_time() - time < ms)
	{
		if (check_time_to_die(philo))
			return (-1); 
		if (check_death(philo))
			return (-1);
		usleep(ms * 0.1);
	}
	return (0);
}
