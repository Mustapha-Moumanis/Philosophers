/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 08:42:20 by mmoumani          #+#    #+#             */
/*   Updated: 2023/03/10 13:37:42 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	g_eat(t_phil *phil)
{
	if (!pthread_mutex_lock(&phil->data->forks[phil->l_fork]))
	{
		if (!pthread_mutex_lock(&phil->data->forks[phil->r_fork]))
		{
			pthread_mutex_lock(&phil->data->m_is_eating);
			phil->is_eating = 1;
			pthread_mutex_unlock(&phil->data->m_is_eating);
			print_msg(phil, "has taken a fork", "\033[0;33m");
			print_msg(phil, "is eating", "\033[0;34m");
			ft_usleep(phil->data->t_e);
			pthread_mutex_lock(&phil->data->m_count);
			phil->count++;
			pthread_mutex_unlock(&phil->data->m_count);
			pthread_mutex_lock(&phil->data->m_time);
			phil->e_time = get_time();
			pthread_mutex_unlock(&phil->data->m_time);
			pthread_mutex_unlock(&phil->data->forks[phil->l_fork]);
			pthread_mutex_unlock(&phil->data->forks[phil->r_fork]);
			g_sleep(phil);
		}
	}
}

void	g_sleep(t_phil *phil)
{
	print_msg(phil, "is sleeping", "\033[0;32m");
	ft_usleep(phil->data->t_s);
	pthread_mutex_lock(&phil->data->m_time);
	phil->e_time = get_time();
	pthread_mutex_unlock(&phil->data->m_time);
	pthread_mutex_lock(&phil->data->m_is_eating);
	phil->is_eating = 0;
	pthread_mutex_unlock(&phil->data->m_is_eating);
	print_msg(phil, "is thinking", "\033[0;35m");
}
