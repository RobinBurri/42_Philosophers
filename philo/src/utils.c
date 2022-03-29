/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:24:51 by rburri            #+#    #+#             */
/*   Updated: 2022/03/29 08:58:18 by rburri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i])
		i++;
	return (i);
}

int	err_msg(char *s)
{
	if (s)
		write(1, s, ft_strlen(s));
	return (1);
}

int	ft_atoi(char *s)
{
	int	i;
	int	res;
	int	sign;

	if (!s)
		return (0);
	i = 0;
	sign = 1;
	res = 0;
	while (s[i] == '\t' || s[i] == '\n' || s[i] == '\v' || s[i] == '\f'
		|| s[i] == '\r' || s[i] == ' ')
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
		res = (res * 10) + (s[i++] - '0');
	return (res * sign);
}

// return value in millisecondes
long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	print_msg(t_philo *philo, char *str)
{
	long long	time;
	long long	now;

	now = get_time();
	time = now - philo->data->time_of_creation;
	printf("%lld\t %d\t %s\n", time, philo->philo_num, str);
}
