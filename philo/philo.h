/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 15:02:01 by efarhat           #+#    #+#             */
/*   Updated: 2023/06/22 14:43:49 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

// # define NB_PH 0
// # define T_DIE 1
// # define T_EAT 2
// # define T_SLEEP 3
// # define NB_MEALS 4

//ARGS STRUCT
typedef struct s_args
{
	int				nb_ph;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				nb_meals;
	pthread_mutex_t	state;
	int				dead;
	pthread_mutex_t	m_dead;
	pthread_mutex_t	meals;
	int				nb_ph_meals;
}		t_args;

// PHILOS STRUCT
typedef struct s_philos
{
	int				num_ph;
	t_args			*args;
	pthread_mutex_t	*lf;
	pthread_mutex_t	*rf;
	pthread_t		t_id;
	long long		start;
	pthread_mutex_t	l_eat;
	long long		last_eat;
	int				nb_meals;
}			t_philos;

int				error(char *str);

//CHECKING ARGUMENTS
int				check_args(char *argv[]);

//INIT UTILS
pthread_mutex_t	*init_forks(int np);
t_args			*init_args(char *argv[]);
t_philos		*init_philos(t_args *args, pthread_mutex_t *forks);

//UTILS
long long		t_now(void);
void			t_sleep(int time);
int				ft_isdigit(int c);
int				ft_atoi(const char *str);

//THREADS CREATION
int				create_threads(t_philos *ph, t_args *args);

//PHILOSPHERS ROUTINE
void			philos_state(char *state, t_philos *ph, t_args *args);
void			eat(t_philos *ph, t_args *args);

#endif
