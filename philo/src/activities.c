/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 10:58:23 by rburri            #+#    #+#             */
/*   Updated: 2022/03/24 11:49:00 by rburri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	sleep(t_data *data)
{
	print_msg(data->philos, "is sleeping");
}

static void	think(t_data *data)
{
	print_msg(data->philos, "is thinking");
}

static void	take_fork(t_data *data)
{
	print_msg(data->philos, "has taken a fork");
}

static void	eat(t_data *data)
{
	print_msg(data->philos, "is eating");
}

void	*activities(void *philo)
{
	t_philo *philo;
	
	philo = (t_philo)*(philo);
	if (philo->philo_num % 2 == 0)
		usleep(100000);
	while (!philo->d)
}