/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ../includes/philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 00:26:22 by mmoumani          #+#    #+#             */
/*   Updated: 2023/02/18 01:01:13 by mmoumani         ###   ########.fr       */
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
    pthread_t philo;
    int id;
    int l_fork;
    int r_fork;
    int count;
    int limit_eat;
    struct args_s *data;

}               phil_t;

typedef struct args_s
{
    int nphil;
    int t_d;
    int t_e;
    int t_s;
    int m_eat;
    long    time;
    int i;
    pthread_mutex_t *forks;
    pthread_mutex_t m_print;
    pthread_mutex_t m_protect;
    phil_t *philos;
}               args_t;

long	ft_atoi(const char *str);
int	ft_isdigit(int c);


#endif