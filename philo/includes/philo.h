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

typedef struct philo
{
    int n_philo;
    int t_die;
    int t_eat;
    int t_sleep;
    int n_must_eat;
}               args_t;


int	ft_atoi(const char *str);
int	ft_isdigit(int c);


#endif