/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salamane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 10:51:29 by salamane          #+#    #+#             */
/*   Updated: 2022/03/26 10:51:30 by salamane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_init(char **argv, int argc, t_philo **info)
{
	int	i;

	(*info)->philos = ft_atoi(argv[1]);
	(*info)->time_to_die = ft_atoi(argv[2]);
	(*info)->time_to_eat = ft_atoi(argv[3]);
	(*info)->time_to_sleep = ft_atoi(argv[4]);
	(*info)->mealcount = 0;
	if (argc == 6)
		(*info)->meals = ft_atoi(argv[5]);
	else
	{
		(*info)->meals = -1;
		(*info)->mealcount = -1;
	}
	(*info)->fork = malloc(sizeof(pthread_mutex_t) * (*info)->philos);
	(*info)->lastmeal = malloc(sizeof(time_t) * (*info)->philos);
	(*info)->turn = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init((*info)->turn, NULL);
	i = 0;
	while (i < (*info)->philos)
	{
		pthread_mutex_init((*info)->fork + i, NULL);
		i++;
	}
}
