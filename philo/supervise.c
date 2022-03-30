/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervise.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 07:40:05 by rburri            #+#    #+#             */
/*   Updated: 2022/03/30 17:48:04 by rburri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*supervise_num_of_meal(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (!data->die)
	{
		if (data->finish_eaten == data->number_of_philos)
			data->all_have_eaten = 1;
		usleep(500);
	}
	return (NULL);
}

void	*supervise(void *arg)
{
	t_philo		*philo;
	long long	now;
	long long	diff;

	philo = (t_philo *)arg;
	while (!philo->data->die)
	{
		now = get_time();
		diff = now - philo->time_last_meal;
		if (diff >= philo->data->time_to_die && philo->data->die == 0)
		{
			pthread_mutex_lock(&philo->data->check_if_dead);
			printf("%lld\t %d\t died\n", now - philo->data->time_of_creation, \
				philo->philo_id);
			philo->data->die = 1;
			pthread_mutex_unlock(&philo->data->check_if_dead);
		}
	}
	return (NULL);
}
