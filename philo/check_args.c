/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 14:59:19 by efarhat           #+#    #+#             */
/*   Updated: 2023/06/05 15:32:44 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

int	check_num(char *nb)
{
	int	i;

	i = 0;
	while (nb[i] && nb[i] == ' ')
		i++;
	if (nb[i] && (nb[i] == '+' || nb[i] == '-'))
		i++;
	while (nb[i])
	{
		if (!ft_isdigit(nb[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_args(char *argv[])
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!check_num(argv[i]))
			return (0);
		i++;
	}
	if (atoi(argv[1]) <= 0 || atoi(argv[2]) <= 0 || atoi(argv[3]) <= 0
		|| atoi(argv[4]) <= 0)
		return (0);
	else if (argv[5] && atoi(argv[5]) <= 0)
		return (0);
	return (1);
}
