/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:53:20 by hleung            #+#    #+#             */
/*   Updated: 2023/08/29 16:44:32 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long	get_time()
{
	struct timeval tv;

	if (gettimeofday(&tv, NULL) == -1)
		return (ft_putstr(GET_TIME), -1);
	

}
