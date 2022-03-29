/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 10:58:23 by rburri            #+#    #+#             */
/*   Updated: 2022/03/29 08:55:12 by rburri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	think(t_philo *philo)
{
	print_msg(philo, "is thinking");
}

static void	ft_sleep(t_philo *philo)
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
	pthread_mutex_lock(&philo->check_philo);
	pthread_mutex_lock(&philo->data->check_die);
	if (!philo->data->die)
	{
		philo->time_last_meal = get_time();
		print_msg(philo, "is eating");
	}
	philo->num_of_meal += 1;
	if (philo->num_of_meal == philo->data->time_must_eat)
		philo->data->finish_eaten += 1;
	pthread_mutex_unlock(&philo->data->check_die);
	usleep(philo->data->time_to_eat * 1000);
	pthread_mutex_unlock(philo->fork_right);
	pthread_mutex_unlock(philo->fork_left);
	pthread_mutex_unlock(&philo->check_philo);
}

void	*activities(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->philo_num % 2 == 0)
		usleep(philo->data->time_to_eat * 1000);
	while (!philo->data->die)
	{
		if (!philo->data->die)
			take_fork(philo);
		if (!philo->data->die)
			eat(philo);
		if (!philo->data->die)
			ft_sleep(philo);
		if (!philo->data->die)
			think(philo);
	}
	return (NULL);
}
