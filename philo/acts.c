/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 10:58:23 by rburri            #+#    #+#             */
/*   Updated: 2022/03/31 06:13:17 by rburri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	think(t_philo *philo)
{
	if (!philo->data->die && philo->data->all_have_eaten != 1)
		print_msg(philo, "is thinking");
}

static void	ft_sleep(t_philo *philo)
{
	if (!philo->data->die && philo->data->all_have_eaten != 1)
	{
		print_msg(philo, "is sleeping");
		usleep(philo->data->time_to_sleep * 1000);
	}
}

static void	taking_up_forks(t_philo *philo)
{
	if (!philo->data->die && philo->data->all_have_eaten != 1)
	{
		pthread_mutex_lock(&philo->data->forks[philo->fork_right]);
		if (!philo->data->die && philo->data->all_have_eaten != 1)
			print_msg(philo, "has taken a fork");
		pthread_mutex_lock(&philo->data->forks[philo->fork_left]);
		if (!philo->data->die && philo->data->all_have_eaten != 1)
			print_msg(philo, "has taken a fork");
	}
}

static void	eat(t_philo *philo)
{
	if (!philo->data->die && philo->data->all_have_eaten != 1)
	{
		philo->time_last_meal = get_time();
		print_msg(philo, "is eating");
	}
	usleep(philo->data->time_to_eat * 1000);
	pthread_mutex_unlock(&philo->data->forks[philo->fork_right]);
	pthread_mutex_unlock(&philo->data->forks[philo->fork_left]);
	philo->num_of_meal += 1;
	if (philo->num_of_meal == philo->data->time_must_eat)
	{
		pthread_mutex_lock(&philo->check_meals);
		philo->data->finish_eaten += 1;
		pthread_mutex_unlock(&philo->check_meals);
	}
}

void	*acts(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->data->number_of_philos == 1)
		usleep(philo->data->time_to_die * 1000);
	else if (philo->philo_id % 2 == 0)
		usleep(philo->data->time_to_eat * 100);
	while (!philo->data->die && philo->data->all_have_eaten != 1)
	{
		taking_up_forks(philo);
		eat(philo);
		ft_sleep(philo);
		think(philo);
	}
	return (NULL);
}
