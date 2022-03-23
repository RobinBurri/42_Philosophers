/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 10:49:50 by rburri            #+#    #+#             */
/*   Updated: 2022/03/23 07:58:47 by rburri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void *eat(void *arg)
{
	int index;
	uint64_t time;
	index = *(int *)arg;
	time = get_time();
	printf("philos no: %d, time: %lld\n", index, time);
	free(arg);
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_data data;
	parse_args_init(&data, argc, argv);
	// pthread_mutex_t fork_mutex[data.number_of_philos];
	// pthread_t philos[data.number_of_philos];
	// for (int i = 0; i < data.number_of_philos; i++)
	// {
	// 	pthread_mutex_init(&fork_mutex[i], NULL);
	// 	printf("mutex crreated\n");
	// }
	// for (int i = 0; i < data.number_of_philos; i++)
	// {
	// 	int *a = malloc(sizeof(int));
	// 	*a = i;
	// 	if (pthread_create(&philos[i], NULL, &eat, a) != 0)
	// 		printf("Failed to create Philos\n");
	// 	printf("philos crreated\n");
	// }

	// for (int i = 0; i < data.number_of_philos; i++)
	// {
	// 	if (pthread_join(philos[i], NULL) != 0)
	// 		printf("Failed to join philos\n");
	// }

	// for (int i = 0; i < data.number_of_philos; i++)
	// {
	// 	pthread_mutex_destroy(&fork_mutex[i]);
	// }
	printf("num philos: %d\n", data.number_of_philos);
	printf("time to die: %d\n", data.time_to_die);
	printf("time to eat: %d\n", data.time_to_eat);
	printf("time to sleep: %d\n", data.time_to_sleep);
	printf("must eat: %d\n", data.time_must_eat);
	
	return (OK);
}
