/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:22:59 by rburri            #+#    #+#             */
/*   Updated: 2022/03/23 09:31:32 by rburri           ###   ########.fr       */
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

# define ARG_ERR "Error: bad arguments\n"
# define NUM_ERR "Error: some args are not numbers\n"

typedef struct s_data
{
	int			number_of_philos;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			time_must_eat;
}				t_data;

int			parse_args_init(t_data *data, int argc, char **argv);

//UTILS
int			get_time(void);
int			err_msg(char *s);
int			ft_strlen(char *s);
int			ft_atoi(char *s);

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
- 
*/