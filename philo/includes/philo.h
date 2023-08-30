/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:26:12 by hleung            #+#    #+#             */
/*   Updated: 2023/08/30 15:26:49 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# define ARG_NUM "Wrong number of arguments!\n"
# define INV_FORM "Invalid argument format!\n"
# define LIM "Argument outside of integer range!\n"
# define MALLOC "Error occurred during malloc!\n"
# define ERR_THR "Error creating threads!\n"
# define ERR_JOIN "Error joining threads!\n"
# define GET_TIME "Error occurred gettimeofday!\n"
# define FORK "has taken a fork\n"
# define EAT "is eating\n"
# define THINK "is thinking\n"
# define SLEEP "is sleeping\n"
# define DIE "died\n"
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <limits.h>

typedef struct s_philo
{
	int				id;
	suseconds_t		last_eat;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_eat;
	suseconds_t		time_of_start;
	t_philo			*philos;
	pthread_t		*threads;
	pthread_mutex_t	start;
	pthread_mutex_t	died;
	pthread_mutex_t	*forks;
}	t_data;

void		ft_putstr(char *str);
void		print_log(int timestamp, int philo, char *action);
int			parse(int argc, char **argv, t_data *data);
int			data_init(int argc, char **argv, t_data *data);
suseconds_t	get_time(void);
void		philo_init(t_data *data);
void		free_data(t_data *data);
#endif
