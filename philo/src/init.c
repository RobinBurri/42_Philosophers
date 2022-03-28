/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:44:47 by rburri            #+#    #+#             */
/*   Updated: 2022/03/28 07:50:47 by rburri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	check_if_is_num(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] < '0' || argv[i] > '9')
			return (ERR);
		i++;
	}
	return (OK);
}

static int	check_entries(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (check_if_is_num(argv[i]))
			return (ERR);
		i++;
	}
	return (OK);
}

int	parse_args_init(t_data *data, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (err_msg(ARG_ERR));
	if (check_entries(argc, argv))
		return (err_msg(NUM_ERR));
	data->number_of_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->time_must_eat = ft_atoi(argv[5]);
	else
		data->time_must_eat = -1;
	data->die = 0;
	return (OK);
}

int	init_philos(t_data *data)
{
	int	i;

	i = 0;
	data->philos = malloc(sizeof(t_philo) * data->number_of_philos);
	if (data->philos == 0)
		return (err_msg(MAL_ERR));
	data->forks = malloc(sizeof(pthread_mutex_t) * data->number_of_philos);
	if (data->forks == 0)
		return (err_msg(MAL_ERR));
	while (i < data->number_of_philos)
	{
		data->philos[i].philo_num = i;
		pthread_mutex_init(&data->forks[i], NULL);
		if (i == 0)
			data->philos[i].fork_left = &data->forks[data->number_of_philos - 1];
		else
			data->philos[i].fork_left = &data->forks[i - 1];
		data->philos[i].fork_right = &data->forks[i];
		i++;
	}
	return (OK);
}
