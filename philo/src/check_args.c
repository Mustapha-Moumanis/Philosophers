/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 09:36:06 by mmoumani          #+#    #+#             */
/*   Updated: 2023/03/10 13:43:51 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_isdigit(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((s[0] == '+' || s[0] == '-') && (!s[1] || !ft_isdigit(s[1])))
			return (0);
		if (!ft_isdigit(s[i]) && s[i] != '+' && s[i] != '-')
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
		if (!check_isdigit(av[i]) || !(ft_atoi(av[i]) > 0))
			return (0);
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

	pthread_mutex_lock(&data->m_is_eating);
	pthread_mutex_lock(&data->m_time);
	time = (get_time() - data->time) - data->philos[i].e_time;
	pthread_mutex_unlock(&data->m_time);
	if (time >= (long)data->t_d)
		if (data->philos[i].is_eating == 0)
			return (print_msg(&data->philos[i], "died", "\033[0;31m"));
	pthread_mutex_unlock(&data->m_is_eating);
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
			if (check_time_of_die(data, i))
				return (1);
			i++;
		}
	}
	return (0);
}
