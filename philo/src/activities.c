/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 10:58:23 by rburri            #+#    #+#             */
/*   Updated: 2022/03/25 07:34:54 by rburri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	think(t_philo *philo)
{
	print_msg(philo, "is thinking");
}

static void	sleep(t_philo *philo)
{
	print_msg(philo, "is sleeping");
	usleep(philo->data->time_to_sleep * 1000);
}

static void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_right);
	print_msg(philo, "has taken a fork");
	pthread_mutex_lock(philo->fork_left);
	print_msg(philo, "has taken a fork");
}

static void	eat(t_philo *philo)
{
	print_msg(philo, "is eating");
}

void	*activities(void *arg)
{
	t_philo *philo;
	
	philo = (t_philo*)arg;
	if (philo->philo_num % 2 == 0)
		usleep(philo->data->time_to_eat * 1000);
	while (!philo->data->end)
	{
		take_fork(philo);
		eat(philo);
		sleep(philo);
		think(philo);
	}
	return (NULL);
}
