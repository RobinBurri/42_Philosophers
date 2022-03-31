/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 10:49:50 by rburri            #+#    #+#             */
/*   Updated: 2022/03/31 06:40:00 by rburri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philos_creation(t_data *data)
{
	pthread_t	supervisor;
	int			i;

	i = 0;
	data->time_of_creation = get_time();
	while (i < data->number_of_philos)
	{
		data->philos[i].time_last_meal = data->time_of_creation;
		pthread_create(&data->philos[i].life, NULL, acts, &data->philos[i]);
		pthread_create(&supervisor, NULL, supervise, &data->philos[i]);
		pthread_detach(supervisor);
		i++;
	}
	if (data->time_must_eat != -1)
	{
		pthread_create(&supervisor, NULL, supervise_num_of_meal, data);
		pthread_detach(supervisor);
	}
}

static void	philos_join(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philos)
	{
		pthread_join(data->philos[i].life, NULL);
		pthread_mutex_destroy(&data->philos[i++].check_meals);
	}
	i = 0;
	while (i < data->number_of_philos)
		pthread_mutex_destroy(&data->forks[i++]);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 5 || argc > 6)
		return (err_msg(ARG_ERR));
	if (parse_args_init(&data, argc, argv))
		return (1);
	if (init_mutex(&data))
		return (1);
	philos_creation(&data);
	philos_join(&data);
	return (0);
}
