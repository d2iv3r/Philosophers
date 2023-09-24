/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:15:26 by efarhat           #+#    #+#             */
/*   Updated: 2023/05/11 14:44:25 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	t_now(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) != 0)
		return (error("Error : gettimeofday!\n"), 0);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	t_sleep(int time)
{
	long long	start;

	start = t_now();
	while (t_now() - start < time)
		usleep(100);
}
