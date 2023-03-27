/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:14:27 by mmoumani          #+#    #+#             */
/*   Updated: 2023/03/19 00:58:21 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	initialize_tab(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nphil)
	{
		data->all_eat[i] = 0;
		i++;
	}
}

void	ft_append(char **av, t_data *data, int n_arg)
{
	int	i;

	i = 1;
	data->nphil = ft_atoi(av[1]);
	data->t_d = ft_atoi(av[2]);
	data->t_e = ft_atoi(av[3]);
	data->t_s = ft_atoi(av[4]);
	if (n_arg == 6)
	{
		data->m_eat = ft_atoi(av[5]);
		data->all_eat = malloc(data->nphil * sizeof(int));
		if (!data->all_eat)
			return ;
		initialize_tab(data);
	}
}

void	create_forks(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(data->nphil * sizeof(pthread_mutex_t));
	if (!data->forks)
		return ;
	while (i < data->nphil)
		pthread_mutex_init(&data->forks[i++], NULL);
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

void	create_philo(t_data *d)
{
	int	i;

	i = 0;
	d->philos = malloc(d->nphil * sizeof(t_phil));
	if (!d->philos)
		return ;
	d->time = get_time();
	while (i < d->nphil)
	{
		d->philos[i] = (t_phil){0};
		d->philos[i].id = i;
		d->philos[i].l_fork = i;
		d->philos[i].r_fork = (i + 1) % d->nphil;
		d->philos[i].data = d;
		if (pthread_create(&d->philos[i].philo, NULL, &routine, &d->philos[i]))
			return ;
		usleep(100);
		i++;
	}
}
