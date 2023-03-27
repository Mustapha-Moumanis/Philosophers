/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:17:35 by mmoumani          #+#    #+#             */
/*   Updated: 2023/03/19 00:48:23 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	print_error(char *msg)
{
	printf("\033[0;31m%s\n", msg);
	return (0);
}

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

void	inisialize_mutex(t_data *data)
{
	pthread_mutex_init(&data->m_print, NULL);
	pthread_mutex_init(&data->m_is_eating, NULL);
	pthread_mutex_init(&data->m_time, NULL);
	pthread_mutex_init(&data->m_count, NULL);
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	*data = (t_data){0};
	if (ac == 5 || ac == 6)
	{
		if (check_args(av))
		{
			inisialize_mutex(data);
			ft_append(av, data, ac);
			create_forks(data);
			create_philo(data);
			check_death(data);
			return (0);
		}
	}
	else
	{
		print_error("Error :\nYou need 4 / 5 args :\n1 : number of philosophers");
		print_error("2 : time to die\n3 : time to eat\n4 : time to sleep");
		print_error("5 : (optional) number of times each philosopher must eat");
	}
}
