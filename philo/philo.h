/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:22:59 by rburri            #+#    #+#             */
/*   Updated: 2022/02/08 11:59:49 by rburri           ###   ########.fr       */
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

# define ARG_ERR "Error: bad arguments\n"

typedef struct s_data
{
	int			number_of_philos;
	uint32_t	time_to_die;
	uint32_t	time_to_eat;
	uint32_t	time_to_sleep;
	int			time_must_eat;
}				t_data;

//UTILS
int	err_msg(char *s);
int	strlen(char *s);

#endif