/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:17:35 by mmoumani          #+#    #+#             */
/*   Updated: 2023/03/10 13:30:44 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	print_msg(t_phil *phil, char *action, char *color)
{
	long	time;

	pthread_mutex_lock(&phil->data->m_print);
	time = get_time() - phil->data->time;
	printf("%s%ld ms %d %s\n", color, time, phil->id + 1, action);
	if (ft_strcmp(action, "died"))
		pthread_mutex_unlock(&phil->data->m_print);
	return (1);
}

void	*routine(void *philos)
{
	t_phil	*phil;

	phil = (t_phil *)philos;
	while (1)
	{
		g_eat(phil);
	}
	return (NULL);
}

void	inisialize_mutex(t_data *data)
{
	pthread_mutex_init(&data->m_print, NULL);
	pthread_mutex_init(&data->m_is_eating, NULL);
	pthread_mutex_init(&data->m_time, NULL);
	pthread_mutex_init(&data->m_protect, NULL);
	pthread_mutex_init(&data->m_count, NULL);
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	*data = (t_data){0};
	if (ac == 5 || ac == 6)
	{
		if (check_args(av))
		{
			inisialize_mutex(data);
			ft_append(av, data, ac);
			create_forks(data);
			create_philo(data);
			if (check_death(data))
				return (0);
			return (0);
		}
	}
	else
	{
		printf("Error :\nYou need 4 / 5 args :\n1 : number of philosophers\n");
		printf("2 : time to die\n3 : time to eat\n4 : time to sleep\n");
		printf("5 : (optional) number of times each philosopher must eat\n");
	}
}
