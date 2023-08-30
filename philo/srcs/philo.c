/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:25:59 by hleung            #+#    #+#             */
/*   Updated: 2023/08/29 15:53:07 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
#include <stdio.h>

int		data_init(int argc, char **argv, t_data *data);
void	free_data(t_data *data);

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 5 || argc > 6)
		return (ft_putstr(ARG_NUM), 1);
	if (data_init(argc, argv, &data) == -1)
		return (free_data(&data), 1);
	philo_init(&data);
	//philo(argv);
	free_data(&data);
	return (0);
}
