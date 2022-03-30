/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 10:58:23 by rburri            #+#    #+#             */
/*   Updated: 2022/03/30 18:47:10 by rburri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	think(t_philo *philo)
{
	print_msg(philo, "is thinking");
}

static void	ft_sleep(t_philo *philo)
{
	print_msg(philo, "is sleeping");
	usleep(philo->data->time_to_sleep * 1000);
}

// static void	take_fork(t_philo *philo)
// {
// 	pthread_mutex_lock(philo->fork_right);
// 	print_msg(philo, "has taken a fork");
// 	pthread_mutex_lock(philo->fork_left);
// 	print_msg(philo, "has taken a fork");
// }

static void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_right);
	print_msg(philo, "has taken a fork");
	printf("philo no %d\ttake : %p\n", philo->philo_id, &philo->fork_right);
	pthread_mutex_lock(philo->fork_left);
	print_msg(philo, "has taken a fork");
	printf("philo no %d\ttake : %p\n", philo->philo_id, &philo->fork_left);
	if (!philo->data->die)
	{
		philo->time_last_meal = get_time();
	pthread_mutex_lock(&philo->check_meals);
		print_msg(philo, "is eating");
	}
	usleep(philo->data->time_to_eat * 1000);
	philo->num_of_meal += 1;
	if (philo->num_of_meal == philo->data->time_must_eat)
		philo->data->finish_eaten += 1;
	pthread_mutex_unlock(&philo->check_meals);
	pthread_mutex_unlock(philo->fork_right);
	printf("philo no %d\tdrop : %p\n", philo->philo_id, &philo->fork_right);
	pthread_mutex_unlock(philo->fork_left);
	printf("philo no %d\tdrop : %p\n", philo->philo_id, &philo->fork_left);
}

void	*activities(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->data->number_of_philos == 1)
		usleep(philo->data->time_to_die * 1000);
	else if (philo->philo_id % 2 == 0)
		usleep(philo->data->time_to_eat * 900);
	while (!philo->data->die && philo->data->all_have_eaten != 1)
	{
		// if (!philo->data->die)
		// 	take_fork(philo);
		eat(philo);
		if (!philo->data->die)
			ft_sleep(philo);
		if (!philo->data->die)
			think(philo);
	}
	return (NULL);
}
