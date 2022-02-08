/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:24:51 by rburri            #+#    #+#             */
/*   Updated: 2022/02/08 12:00:41 by rburri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	strlen(char *s)
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
		write(1, s, strlen(s));
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
