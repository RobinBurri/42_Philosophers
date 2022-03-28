/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervise.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 07:40:05 by rburri            #+#    #+#             */
/*   Updated: 2022/03/28 09:10:16 by rburri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// void	*supervise_num_of_meal(void *arg)
// {
// 	t_data	*data;
// 	data = (t_data*)arg;
// 	while (!data->die)
// 	{
// 		pthread_mutex_lock(&data->check_die);
// 		if (data->time_must_eat == data)
// 	}
	// return (NULL);
// }

void *supervise(void *arg)
{
	t_philo		*philo;
	long long	now;
	long long	diff;
	
	philo = (t_philo*)arg;
	while (!philo->data->die)
	{
		pthread_mutex_lock(&philo->data->check_die);
		now = get_time();
		diff = now - philo->time_last_meal;
		if (diff >= philo->data->time_to_die && philo->data->die == 0)
		{
			printf("%lld %d died\n", now, philo->philo_num);
			philo->data->die = 1;	
		}
		pthread_mutex_unlock(&philo->data->check_die);
	}
	return (NULL);
}