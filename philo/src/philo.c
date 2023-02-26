/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 00:32:55 by mmoumani          #+#    #+#             */
/*   Updated: 2023/02/26 06:37:01 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void ft_error(char *str)
{
	printf("Error\n");
	printf("%s\n", str);
}

int check_isdigit (char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if ((s[0] == '+' || s[0] == '-') && (!s[1] || !ft_isdigit(s[1])))
			return(0);
		if (!ft_isdigit(s[i]) && s[i] != '+' && s[i] != '-')
			return(0);
		i++;
	}
	return (1);
}

int check_ispositive (char *s)
{
	int nb;

	nb = ft_atoi(s);
	return (nb > 0);
}

void    ft_append(char **av, args_t *args, int n_arg)
{
	int i;

	i = 1;
	args->nphil = ft_atoi(av[1]);
	args->t_d = ft_atoi(av[2]);
	args->t_e = ft_atoi(av[3]);
	args->t_s = ft_atoi(av[4]);
	if (n_arg == 6)
		args->m_eat = ft_atoi(av[5]);
}

int check_args (char **av, args_t *args)
{
	int i;

	i = 1;
	while (av[i])
	{
		if (!check_isdigit(av[i]) || !check_ispositive(av[i]))
			return(0);
		i++;
	}
	ft_append(av, args, i);
	return (1);
}



void *routine (void *arg)
{
	args_t *val = (args_t *)arg;
	printf("ha wahed %d\n", val->philos[val->i].id);
	val->i++;
	return (NULL);
}

long get_time()
{
	struct timeval begin;
	gettimeofday(&begin, NULL);
	return (begin.tv_sec * 1000 + begin.tv_usec / 1000);
}

void create_philo(args_t *arg)
{
	int i;

	i = 0;
	while (i < arg->nphil)
	{
		arg->philos[i].id = i;
		arg->philos[i].l_fork = i;
		arg->philos[i].r_fork = (i + 1) % arg->nphil;
		arg->philos[i].count = 0;
		arg->philos[i].limit_eat = arg->m_eat;
		pthread_mutex_init(&arg->forks[i], NULL);
		pthread_create(&arg->philos[i].philo, NULL, &routine, arg);
		usleep(100);
		// pthread_join(arg->philos[i].philo, NULL);
		i++;
	}
	i = 0;
	while (i < arg->nphil)
		pthread_join(arg->philos[i++].philo, NULL);
}

int main (int ac, char **av)
{
	args_t arg;
	// int i = 0;

	arg = (args_t){0};
	if (ac == 5 || ac == 6)
	{
		if (check_args(av, &arg))
		{
			// create thread
			// arg.philo = malloc(1);
			arg.philos = malloc(arg.nphil * sizeof(phil_t));
			arg.forks = malloc(arg.nphil * sizeof(pthread_mutex_t));
			arg.time = get_time();
			pthread_mutex_init(&arg.m_protect, NULL);
			pthread_mutex_lock(&arg.m_protect);
			pthread_mutex_unlock(&arg.m_protect);
			create_philo(&arg);
			usleep(1000);
			printf("time %ldms ALL NICE \n", get_time() - arg.time);
		}
	}
	else
	{
		printf("Error :\nYou need 4 / 5 args :\n1 : number of philosophers\n");
		printf("2 : time to die\n3 : time to eat\n4 : time to sleep\n");
		printf("5 : (optional) number of times each philosopher must eat\n");
	}
}