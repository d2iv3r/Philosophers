/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 15:05:36 by efarhat           #+#    #+#             */
/*   Updated: 2023/06/22 17:22:21 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error(char *str)
{
	printf("%s", str);
	return (1);
}

int	main(int carg, char *varg[])
{
	t_args				*args;
	t_philos			*philos;
	pthread_mutex_t		*forks;

	if (carg != 5 && carg != 6)
		return (error("Invalid Number of Args!!\n"));
	else
	{
		if (!check_args(varg))
			return (error("Invalid Args!\n"));
		args = init_args(varg);
		forks = init_forks(args->nb_ph);
		philos = init_philos(args, forks);
		if (!forks || !philos || !args)
			return (error("Error : Initialization utils!\n"));
		if (!create_threads(philos, args))
			return (error("Error : threads!\n"));
	}
	return (0);
}
