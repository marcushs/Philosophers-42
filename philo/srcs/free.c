/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:30:23 by hleung            #+#    #+#             */
/*   Updated: 2023/08/30 13:25:47 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	free_and_null(void	**arr)
{
	free(*arr);
	*arr = NULL;
}

void	free_data(t_data *data)
{
	if (data->philos)
		free_and_null((void *)&data->philos);
	if (data->threads)
		free_and_null((void *)&data->threads);
	if (data->forks)
		free_and_null((void *)&data->forks);
	pthread_mutex_destroy(&data->start);
	//pthread_mutex_destroy(&data->died);
	// pthread_mutex_destroy(&data->forks);
}

