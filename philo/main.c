/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 10:49:50 by rburri            #+#    #+#             */
/*   Updated: 2022/03/31 07:45:33 by rburri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philos_creation(t_data *d)
{
	pthread_t	supervisor;
	int			i;

	i = 0;
	d->time_of_creation = get_time();
	while (i < d->number_of_philos)
	{
		d->philos[i].time_last_meal = d->time_of_creation;
		pthread_create(&d->philos[i].life, NULL, acts, &d->philos[i]);
		pthread_create(&supervisor, NULL, supervise, &d->philos[i]);
		pthread_detach(supervisor);
		i++;
	}
	if (d->time_must_eat != -1)
	{
		pthread_create(&supervisor, NULL, supervise_num_of_meal, d);
		pthread_detach(supervisor);
	}
}

static void	philos_join(t_data *d)
{
	int	i;

	i = 0;
	while (i < d->number_of_philos)
	{
		pthread_join(d->philos[i].life, NULL);
		pthread_mutex_destroy(&d->philos[i++].check_meals);
	}
	i = 0;
	while (i < d->number_of_philos)
		pthread_mutex_destroy(&d->forks[i++]);
}

int	main(int argc, char **argv)
{
	t_data	d;

	if (argc < 5 || argc > 6)
		return (err_msg(ARG_ERR));
	if (parse_args_init(&d, argc, argv))
		return (1);
	if (init_mutex(&d))
		return (1);
	philos_creation(&d);
	philos_join(&d);
	return (0);
}
