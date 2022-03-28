/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:22:59 by rburri            #+#    #+#             */
/*   Updated: 2022/03/28 09:35:25 by rburri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

# define OK 0
# define ERR 1

# define ARG_ERR "Error: numbers of arguments\nUsage: ./philo num_of_philo \
time_to_die time_to_eat time_to_sleep [time_must_eat]\n"
# define NUM_ERR "Error: some args are not numbers\n"
# define MAL_ERR "Error, malloc failed\n"

typedef struct s_philo
{
	struct s_data	*data;
	pthread_mutex_t	*fork_left; // init_philos
	pthread_mutex_t	*fork_right; // int_philos
	pthread_mutex_t	check_philo;
	int				philo_num;
	int				num_of_meal;
	long long		time_last_meal;
	pthread_t		life; // pthread_create in philos_creation (main)
}					t_philo;

typedef struct s_data
{
	pthread_mutex_t	*forks; //init_philos + malloc_ed
	t_philo			*philos; //malloc_ed 
	int				number_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_must_eat;
	long long		time_of_creation;
	int				die;
	pthread_mutex_t	check_die;
}				t_data;
void	*activities(void *philo);
void	*supervise(void *arg);

// INIT
int			parse_args_init(t_data *data, int argc, char **argv);
int			init_philos(t_data *data);

//UTILS
long long	get_time(void);
int			err_msg(char *s);
int			ft_strlen(char *s);
int			ft_atoi(char *s);
void		print_msg(t_philo *philo, char *str);

#endif

/*
memset, printf, malloc, free, write,
usleep, gettimeofday, pthread_create,
pthread_detach, pthread_join, pthread_mutex_init,
pthread_mutex_destroy, pthread_mutex_lock,
pthread_mutex_unlock
*/

//Arguments:
/*
num of philos
time to die
time to eat
time to sleep
(time must eat)
*/

/*
TODO

- MAKE function to print output with time stamp
- initialize required number of philo, set arguments correctly to them
- How a philo knows when he can try to take forks?
- malloc everything with 0
*/


// mutex_init
// mutex_destroy
// mutex_lock
// mutex_unlock