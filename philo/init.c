/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:44:47 by rburri            #+#    #+#             */
/*   Updated: 2022/03/31 09:04:08 by rburri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_if_is_num(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] < '0' || argv[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

static int	check_entries(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (check_if_is_num(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

static void	init_philos_forks(t_data *d)
{
	int	i;

	i = 0;
	while (i < d->number_of_philos)
	{
		d->philos[i].philo_id = i;
		d->philos[i].num_of_meal = 0;
		d->philos[i].fork_left = i;
		d->philos[i].fork_right = (i + 1) % d->number_of_philos;
		d->philos[i].d = d;
		i++;
	}
}

int	parse_args_init(t_data *d, int argc, char **argv)
{
	if (check_entries(argc, argv))
		return (err_msg(NUM_ERR));
	d->die = 0;
	d->number_of_philos = ft_atoi(argv[1]);
	d->time_to_die = ft_atoi(argv[2]);
	d->time_to_eat = ft_atoi(argv[3]);
	d->time_to_sleep = ft_atoi(argv[4]);
	if (d->number_of_philos > 250 || d->time_to_die < 0 || \
		d->time_to_eat < 0 || d->time_to_sleep < 0)
		return (err_msg(PHILO_ERR));
	if (argc == 6)
	{
		d->time_must_eat = ft_atoi(argv[5]);
		d->all_have_eaten = 0;
		d->finish_eaten = 0;
		if (d->time_must_eat <= 0)
			return (err_msg(MEAL_ERR));
	}
	else
	{
		d->time_must_eat = -1;
		d->all_have_eaten = -1;
	}
	init_philos_forks(d);
	return (0);
}

int	init_mutex(t_data *d)
{
	int	i;

	i = 0;
	while (i < d->number_of_philos)
	{
		if (pthread_mutex_init(&d->forks[i], NULL))
			return (err_msg(MUTEX_ERR));
		if (pthread_mutex_init(&d->philos[i].check_meals, NULL))
			return (err_msg(MUTEX_ERR));
		i++;
	}
	if (pthread_mutex_init(&d->check_if_dead, NULL))
		return (err_msg(MUTEX_ERR));
	return (0);
}
