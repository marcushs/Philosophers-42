/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:30:23 by hleung            #+#    #+#             */
/*   Updated: 2023/08/29 15:46:05 by hleung           ###   ########.fr       */
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
	if (data->forks)
		free_and_null((void *)&data->forks);
}
