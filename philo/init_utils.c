/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:32:37 by efarhat           #+#    #+#             */
/*   Updated: 2023/06/22 17:22:41 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t	*init_forks(int np)
{
	pthread_mutex_t	*forks;
	int				i;

	forks = malloc (sizeof(pthread_mutex_t) * np);
	if (!forks)
		return (NULL);
	i = 0;
	while (i < np)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
			return (NULL);
		i++;
	}
	return (forks);
}

t_args	*init_args(char *argv[])
{
	t_args	*args;

	args = malloc(sizeof(t_args));
	if (!args)
		return (0);
	args->nb_ph = ft_atoi(argv[1]);
	args->t_die = ft_atoi(argv[2]);
	args->t_eat = ft_atoi(argv[3]);
	args->t_sleep = ft_atoi(argv[4]);
	if (argv[5])
		args->nb_meals = ft_atoi(argv[5]);
	else
		args->nb_meals = -1;
	args->nb_ph_meals = 0;
	args->dead = 0;
	if (pthread_mutex_init(&args->state, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&args->meals, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&args->m_dead, NULL) != 0)
		return (0);
	return (args);
}

t_philos	*init_philos(t_args *args, pthread_mutex_t *forks)
{
	t_philos	*philos;
	int			i;

	philos = malloc (sizeof(t_philos) * args->nb_ph);
	if (!philos)
		return (NULL);
	i = 0;
	while (i < args->nb_ph)
	{
		philos[i].num_ph = i + 1;
		philos[i].args = args;
		philos[i].lf = forks + i;
		philos[i].rf = forks + ((i + 1) % args->nb_ph);
		philos[i].start = t_now();
		philos[i].nb_meals = 0;
		if (pthread_mutex_init(&(philos[i].l_eat), NULL) != 0)
			return (NULL);
		i++;
	}
	return (philos);
}
