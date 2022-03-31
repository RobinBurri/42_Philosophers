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
	if (!philo->d->die && philo->d->all_have_eaten != 1)
		print_msg(philo, "is thinking");
}

static void	ft_sleep(t_philo *philo)
{
	if (!philo->d->die && philo->d->all_have_eaten != 1)
	{
		print_msg(philo, "is sleeping");
		ft_usleep(philo->d->time_to_sleep);
	}
}

static void	taking_up_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->d->forks[philo->fork_right]);
	if (!philo->d->die && philo->d->all_have_eaten != 1)
		print_msg(philo, "has taken a fork");
	pthread_mutex_lock(&philo->d->forks[philo->fork_left]);
	if (!philo->d->die && philo->d->all_have_eaten != 1)
		print_msg(philo, "has taken a fork");
}

static void	eat(t_philo *philo)
{
	if (!philo->d->die && philo->d->all_have_eaten != 1)
		print_msg(philo, "is eating");
	philo->time_last_meal = get_time();
	ft_usleep(philo->d->time_to_eat);
	pthread_mutex_unlock(&philo->d->forks[philo->fork_right]);
	pthread_mutex_unlock(&philo->d->forks[philo->fork_left]);
	philo->num_of_meal += 1;
	if (philo->num_of_meal == philo->d->time_must_eat)
	{
		pthread_mutex_lock(&philo->check_meals);
		philo->d->finish_eaten += 1;
		pthread_mutex_unlock(&philo->check_meals);
	}
}

void	*acts(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->d->number_of_philos == 1)
		usleep(philo->d->time_to_die * 1000);
	else if (philo->philo_id % 2 == 0)
		usleep(100);
	while (!philo->d->die && philo->d->all_have_eaten != 1)
	{
		taking_up_forks(philo);
		eat(philo);
		ft_sleep(philo);
		think(philo);
	}
	return (NULL);
}
