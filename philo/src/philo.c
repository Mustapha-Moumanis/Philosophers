/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 00:32:55 by mmoumani          #+#    #+#             */
/*   Updated: 2023/02/18 02:45:54 by mmoumani         ###   ########.fr       */
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
	
	args->n_philo = ft_atoi(av[1]);
	args->t_die = ft_atoi(av[2]);
	args->t_die = ft_atoi(av[3]);
	args->t_sleep = ft_atoi(av[4]);
	if (n_arg == 6)
		args->t_sleep = ft_atoi(av[5]);
}

int check_args (char **av, args_t *args)
{
	int i;

	i = 1;
	while (av[i])
	{
		if (!check_isdigit(av[i]))
		{
			ft_error("chi haja machi digit");
			return(0);
		}
		else if (!check_ispositive(av[i]))
		{
			ft_error("chi haje negative ola = 0");
			return(0);
		}
		i++;
	}
	ft_append(av, args, i);
	return (1);
}

int main (int ac, char **av)
{
	args_t args;

	args = (args_t){0};
	if (ac == 5)
	{
		if (check_args(av, &args))
		{
			printf("ALL NICE \n");
		}
		
	}
	else if (ac == 6)
	{
		if (check_args(av, &args))
		{
			printf("ALL NICE \nn of philo %d\n", args.n_must_eat);
		}
	}
	else
	{
		printf("Error :\nyou need 4 / 5 args :\n1 : number of philosophers\n");
		printf("2 : time to die\n3 : time to eat\n4 : time_to_sleep\n");
		printf("5 : (optional) number of times each philosopher must_eat\n");
	}
}