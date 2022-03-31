/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 08:40:22 by rburri            #+#    #+#             */
/*   Updated: 2022/03/31 09:12:50 by rburri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
// return value in millisecondes
long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_usleep(int ms)
{
	long long	before;
	long long	after;
	long long	t;

	t = ms;
	before = get_time();
	after = before;
	while ((after - before) < t)
	{
		usleep(200);
		after = get_time();
	}
}
