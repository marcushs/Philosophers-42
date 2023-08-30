/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:25:59 by hleung            #+#    #+#             */
/*   Updated: 2023/08/30 15:26:24 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int		data_init(int argc, char **argv, t_data *data);
void	free_data(t_data *data);
int		create_threads(t_data *data);
int		join_threads(t_data *data);
void	*routine();

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 5 || argc > 6)
		return (ft_putstr(ARG_NUM), 1);
	if (data_init(argc, argv, &data) == -1)
		return (free_data(&data), 1);
	philo_init(&data);
	if (create_threads(&data) == -1)
		return (free_data(&data), 1);
	if (join_threads(&data) == -1)
		return (free_data(&data), 1);
	//printf("start time is %ld\n", data.time_of_start);
	//philo(argv);
	free_data(&data);
	return (0);
}
