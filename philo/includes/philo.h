/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:26:12 by hleung            #+#    #+#             */
/*   Updated: 2023/08/29 16:44:18 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# define ARG_NUM "Wrong number of arguments!\n"
# define INV_FORM "Invalid argument format!\n"
# define LIM "Argument outside of integer range!\n"
# define MALLOC "Error occurred during malloc!\n"
# define GET_TIME "Error occurred gettimeofday!\n"
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

typedef struct s_philo
{
	int	id;
}	t_philo;

typedef struct s_data
{
	int				parsed_args[5];
	t_philo			*philos;
	pthread_mutex_t	*forks;
}	t_data;

void	ft_putstr(char *str);
void	print_log(int timestamp, int philo, char *action);
int		parse(int argc, char **argv, t_data *data);
int		data_init(int argc, char **argv, t_data *data);
void	philo_init(t_data *data);
void	free_data(t_data *data);
#endif
