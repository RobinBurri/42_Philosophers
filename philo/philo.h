/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:22:59 by rburri            #+#    #+#             */
/*   Updated: 2022/02/09 18:13:25 by rburri           ###   ########.fr       */
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
	uint32_t	time_to_die;
	uint32_t	time_to_eat;
	uint32_t	time_to_sleep;
	int			time_must_eat;
}				t_data;

int			init(t_data *data, int argc, char **argv);

//UTILS
uint64_t	get_time(void);
int			err_msg(char *s);
int			ft_strlen(char *s);
int			ft_atoi(char *s);

#endif