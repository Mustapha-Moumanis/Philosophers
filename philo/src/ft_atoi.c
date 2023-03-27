/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 00:58:06 by mmoumani          #+#    #+#             */
/*   Updated: 2023/03/18 22:35:32 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	ft_white_space(const char *str, int i)
{
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	return (i);
}

long	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	unsigned long	r;

	i = 0;
	sign = 1;
	r = 0;
	i = ft_white_space(str, i);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r *= 10;
		r += (str[i] - '0');
		i++;
	}
	if (r > 2147483647)
		return (-1);
	return (r * sign);
}
