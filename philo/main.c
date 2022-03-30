/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 10:49:50 by rburri            #+#    #+#             */
/*   Updated: 2022/03/29 08:54:08 by rburri           ###   ########.fr       */
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
		pthread_create(&data->philos->life, NULL, activities, &data->philos[i]);
		pthread_create(&supervisor, NULL, supervise, &data->philos[i]);
		pthread_detach(supervisor);
		i++;
	}
	if (data->time_must_eat != 0)
	{
		pthread_create(&supervisor, NULL, supervise_num_of_meal, data);
		pthread_detach(supervisor);
	}
}

static void	philos_join_free(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philos)
	{
		pthread_join(data->philos[i].life, NULL);
		pthread_mutex_destroy(&data->philos[i++].check_philo);
	}
	free(data->philos);
	i = 0;
	while (i < data->number_of_philos)
		pthread_mutex_destroy(&data->forks[i++]);
	free(data->forks);
}

int	main(int argc, char **argv)
{
	t_data	data;

	memset(&data, 0, sizeof(data));
	if (parse_args_init(&data, argc, argv))
		return (1);
	if (init_philos(&data))
		return (1);
	philos_creation(&data);
	philos_join_free(&data);
	return (0);
}
