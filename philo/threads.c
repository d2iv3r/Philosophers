/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:22:25 by efarhat           #+#    #+#             */
/*   Updated: 2023/06/22 17:23:29 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_if_done(t_philos *phs, t_args *args)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < args->nb_ph)
		{
			pthread_mutex_lock(&(args->meals));
			if (args->nb_ph_meals == args->nb_ph)
				return (1);
			pthread_mutex_unlock(&(args->meals));
			pthread_mutex_lock(&(phs[i].l_eat));
			if ((t_now() - phs[i].last_eat) > args->t_die)
			{
				pthread_mutex_unlock(&(phs[i].l_eat));
				pthread_mutex_lock(&(args->m_dead));
				args->dead = 1;
				pthread_mutex_unlock(&(args->m_dead));
				philos_state("died", &phs[i], args);
				return (1);
			}
			pthread_mutex_unlock(&(phs[i].l_eat));
			i++;
		}
	}
}

void	*routine(void *arg)
{
	t_args		*args;
	t_philos	*ph;

	ph = (t_philos *)arg;
	args = ph->args;
	while (1)
	{
		pthread_mutex_lock(&(args->m_dead));
		if (args->dead)
			return (pthread_mutex_unlock(&(args->m_dead)), NULL);
		pthread_mutex_unlock(&(args->m_dead));
		pthread_mutex_lock(&(args->meals));
		if (args->nb_ph_meals == args->nb_ph)
			return (pthread_mutex_unlock(&(args->meals)), NULL);
		pthread_mutex_unlock(&(args->meals));
		eat(ph, ph->args);
		philos_state("is sleeping", ph, args);
		pthread_mutex_unlock(&(args->state));
		t_sleep(args->t_sleep);
		philos_state("is thinking", ph, args);
		pthread_mutex_unlock(&(args->state));
	}
	return (NULL);
}

int	create_threads(t_philos *ph, t_args *args)
{
	int	i;

	i = 0;
	while (i < args->nb_ph)
	{
		ph[i].last_eat = t_now();
		if (pthread_create(&(ph[i].t_id), NULL, &routine,
				(void *)(ph + i)) != 0)
			return (0);
		if (pthread_detach(ph[i].t_id) != 0)
			return (0);
		if (ph[i].num_ph % 2 != 0)
			usleep(1000);
		i++;
	}
	if (!check_if_done(ph, args))
		return (0);
	return (1);
}
