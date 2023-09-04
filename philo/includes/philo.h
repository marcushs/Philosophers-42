/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:26:12 by hleung            #+#    #+#             */
/*   Updated: 2023/09/04 20:14:31 by hleung           ###   ########.fr       */
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

typedef struct s_fork
{
	pthread_mutex_t	fork;
	int				is_locked;
}	t_fork;

typedef struct s_philo
{
	int				id;
	suseconds_t		last_eat;
	int				eat_count;
	t_fork		*l_fork;
	t_fork		*r_fork;
	pthread_mutex_t eat_lock;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_eat;
	int				is_dead;
	suseconds_t		time_of_start;
	t_philo			*philos;
	t_fork			*forks;
	pthread_t		*threads;
	pthread_mutex_t	start;
	pthread_mutex_t	print;
	pthread_mutex_t	died;
}	t_data;

void		ft_putstr(char *str);
int			parse(int argc, char **argv, t_data *data);
void		print_log(t_philo *philo, char *msg);
int			data_init(int argc, char **argv, t_data *data);
suseconds_t	get_time(void);
void		philo_init(t_data *data);
void		free_data(t_data *data);
int			data_init(int argc, char **argv, t_data *data);
int			create_threads(t_data *data);
int			join_threads(t_data *data);
void		*routine();
void		take_fork(t_philo *philo);
void		eat(t_philo *philo);
void		ft_usleep(int ms);
#endif
