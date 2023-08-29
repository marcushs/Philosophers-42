/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:26:12 by hleung            #+#    #+#             */
/*   Updated: 2023/08/29 11:09:36 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# define ARG_NUM "Wrong number of arguments!\n"
# define INV_FORM "Invalid argument format!\n"
# define LIM "Argument outside of integer range!\n"
# define FORK "has taken a fork\n"
# define EAT "is eating\n"
# define THINK "is thinking\n"
# define SLEEP "is sleeping\n"
# define DIE "died\n"
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <limits.h>

typedef struct s_data
{
	int	parsed_times[4];
}	t_data;

void	ft_putstr(char *str);
void	print_log(int timestamp, int philo, char *action);
int		parse(char **argv, t_data *data);
#endif
