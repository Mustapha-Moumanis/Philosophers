/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:57:22 by mmoumani          #+#    #+#             */
/*   Updated: 2023/03/16 00:34:47 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long	get_time(void)
{
	struct timeval	begin;

	gettimeofday(&begin, NULL);
	return (begin.tv_sec * 1000 + begin.tv_usec / 1000);
}

void	ft_usleep(long time_finish)
{
	long	time_enter;

	time_enter = get_time();
	while (get_time() - time_enter < time_finish)
		usleep(100);
}
