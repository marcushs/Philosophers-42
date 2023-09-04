/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:53:20 by hleung            #+#    #+#             */
/*   Updated: 2023/09/03 21:11:37 by hleung           ###   ########.fr       */
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

void	ft_usleep(int ms)
{
	suseconds_t	time;

	time = get_time();
	while (get_time() - time < ms)
		usleep(ms * 0.1);
}
