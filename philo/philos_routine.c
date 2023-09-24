/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:25:18 by efarhat           #+#    #+#             */
/*   Updated: 2023/06/22 16:27:44 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philos_state(char *state, t_philos *ph, t_args *args)
{
	long long	tstamp;

	pthread_mutex_lock(&(args->state));
	tstamp = t_now() - ph->start;
	printf("%lld %d %s\n", tstamp, ph->num_ph, state);
}

void	eat(t_philos *ph, t_args *args)
{
	pthread_mutex_lock(ph->lf);
	philos_state("has taken a fork", ph, args);
	pthread_mutex_unlock(&(args->state));
	pthread_mutex_lock(ph->rf);
	philos_state("has taken a fork", ph, args);
	pthread_mutex_unlock(&(args->state));
	philos_state("is eating", ph, args);
	pthread_mutex_unlock(&(args->state));
	pthread_mutex_lock(&(args->meals));
	ph->nb_meals++;
	if (ph->nb_meals == args->nb_meals)
		args->nb_ph_meals++;
	pthread_mutex_unlock(&(args->meals));
	pthread_mutex_lock(&(ph->l_eat));
	ph->last_eat = t_now();
	pthread_mutex_unlock(&(ph->l_eat));
	t_sleep(args->t_eat);
	pthread_mutex_unlock(ph->lf);
	pthread_mutex_unlock(ph->rf);
}
