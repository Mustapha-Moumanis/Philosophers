/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 00:26:22 by mmoumani          #+#    #+#             */
/*   Updated: 2023/03/19 00:59:28 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct philo_data
{
	pthread_t		philo;
	int				id;
	int				l_fork;
	int				r_fork;
	int				count;
	long			e_time;
	int				is_eating;
	struct s_data	*data;
}					t_phil;

typedef struct s_data
{
	int					nphil;
	int					t_d;
	int					t_e;
	int					t_s;
	int					m_eat;
	long				time;
	int					*all_eat;
	pthread_mutex_t		*forks;
	pthread_mutex_t		m_print;
	pthread_mutex_t		m_time;
	pthread_mutex_t		m_is_eating;
	pthread_mutex_t		m_count;
	t_phil				*philos;
}						t_data;

int		ft_strcmp(char *s1, char *s2);
long	ft_atoi(const char *str);
int		ft_isdigit(int c);
long	get_time(void);
void	ft_usleep(long time_finish);
int		check_isdigit(char *s);
int		check_args(char **av);
void	ft_append(char **av, t_data *args, int n_arg);
void	initialize_tab(t_data *data);
void	create_forks(t_data *data);
void	create_philo(t_data *data);
void	*routine(void *philos);
void	g_eat(t_phil *phil);
void	g_sleep(t_phil *phil);
int		print_msg(t_phil *phil, char *action, char *color);
int		print_error(char *msg);
int		check_eat(t_data *data);
int		check_death(t_data *data);

#endif