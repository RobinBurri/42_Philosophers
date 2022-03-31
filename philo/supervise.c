/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervise.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 07:40:05 by rburri            #+#    #+#             */
/*   Updated: 2022/03/31 09:12:28 by rburri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*supervise_num_of_meal(void *arg)
{
	t_data	*d;

	d = (t_data *)arg;
	while (!d->die && d->all_have_eaten != 1)
	{
		if (d->finish_eaten == d->number_of_philos)
			d->all_have_eaten = 1;
		usleep(50000);
	}
	return (NULL);
}

void	*supervise(void *arg)
{
	t_philo		*philo;
	long long	now;
	long long	diff;

	philo = (t_philo *)arg;
	while (!philo->d->die && philo->d->all_have_eaten != 1)
	{
		now = get_time();
		diff = now - philo->time_last_meal;
		if (diff >= philo->d->time_to_die && philo->d->die == 0)
		{
			pthread_mutex_lock(&philo->d->check_if_dead);
			philo->d->die = 1;
			pthread_mutex_unlock(&philo->d->check_if_dead);
			printf("%lld\t \033[0;31m%d\t died\n\033[0m", \
			now - philo->d->time_of_creation, philo->philo_id);
		}
	}
	return (NULL);
}
