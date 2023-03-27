/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 09:36:06 by mmoumani          #+#    #+#             */
/*   Updated: 2023/03/19 00:02:03 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_isdigit(char *s)
{
	int	i;

	i = 0;
	if ((s[i] == '+' || s[i] == '-') && s[1])
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_args(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (!check_isdigit(av[i]))
			return (print_error("One of the args is not a number."));
		else if (!(ft_atoi(av[i]) > 0))
			return (print_error("The number has to be between 1 and maxint."));
		i++;
	}
	return (1);
}

int	check_eat(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nphil)
	{
		if (data->all_eat[i] != 1)
			return (0);
		i++;
	}
	return (1);
}

int	check_time_of_die(t_data *data, int i)
{
	long	time;
	long	dtime;

	dtime = (long)data->t_d;
	pthread_mutex_lock(&data->m_time);
	time = (get_time() - data->time) - data->philos[i].e_time;
	pthread_mutex_unlock(&data->m_time);
	if (time >= dtime)
		return (print_msg(&data->philos[i], "died", "\033[0;31m"));
	return (0);
}

int	check_death(t_data *data)
{
	int		i;

	while (1337)
	{
		i = 0;
		while (i < data->nphil)
		{
			if (data->m_eat != 0)
			{
				pthread_mutex_lock(&data->m_count);
				if (!data->all_eat[i] && data->philos[i].count >= data->m_eat)
					data->all_eat[i] = 1;
				pthread_mutex_unlock(&data->m_count);
				if (check_eat(data) == 1)
					return (0);
			}
			pthread_mutex_lock(&data->m_is_eating);
			if (data->philos[i].is_eating == 0)
				if (check_time_of_die(data, i))
					return (1);
			pthread_mutex_unlock(&data->m_is_eating);
			i++;
		}
	}
	return (0);
}
