/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:22:59 by rburri            #+#    #+#             */
/*   Updated: 2022/03/31 09:11:52 by rburri           ###   ########.fr       */
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

# define ARG_ERR "Error: numbers of arguments\nUsage: ./philo num_of_philo \
time_to_die time_to_eat time_to_sleep [time_must_eat]\n"
# define NUM_ERR "Error: some args are not numbers\n"
# define PHILO_ERR "Some args are incorrect: only positive \
numbers and max philosopher = 250\n"
# define MEAL_ERR "Number of Meals must be > 0\n"
# define MUTEX_ERR "Error init mutex\n"

typedef struct s_philo
{
	int				fork_left;
	int				fork_right;
	pthread_mutex_t	check_meals;
	int				philo_id;
	pthread_t		life;
	int				num_of_meal;
	long long		time_last_meal;
	struct s_d		*d;
}				t_philo;

typedef struct s_d
{
	pthread_mutex_t	forks[250];
	t_philo			philos[250];
	pthread_mutex_t	check_if_dead;
	int				number_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	long long		time_of_creation;
	int				die;
	int				time_must_eat;
	int				finish_eaten;
	int				all_have_eaten;
}				t_data;

//UTILS
int			err_msg(char *s);
int			ft_strlen(char *s);
int			ft_atoi(char *s);
void		print_msg(t_philo *philo, char *str);
// INIT
int			parse_args_init(t_data *d, int argc, char **argv);
int			init_mutex(t_data *d);
//Threads function
void		*acts(void *philo);
void		*supervise(void *arg);
void		*supervise_num_of_meal(void *arg);
//TIME
long long	get_time(void);
void		ft_usleep(int ms);

#endif
