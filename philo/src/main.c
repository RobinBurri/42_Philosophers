/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 10:49:50 by rburri            #+#    #+#             */
/*   Updated: 2022/03/24 09:40:52 by rburri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void *eat(void *arg)
{
	int index;
	int time;
	index = *(int *)arg;
	time = get_time();
	printf("philos no: %d, time: %d\n", index, time);
	free(arg);
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_data data;
	
	memset(&data, 0, sizeof(data));
	if (parse_args_init(&data, argc, argv))
		return (1);
	if (init_philos(data))
		return (1);
	// Create philos
	// free philos
	printf("num philos: %d\n", data.number_of_philos);
	printf("time to die: %d\n", data.time_to_die);
	printf("time to eat: %d\n", data.time_to_eat);
	printf("time to sleep: %d\n", data.time_to_sleep);
	printf("must eat: %d\n", data.time_must_eat);
	
	return (OK);
}
