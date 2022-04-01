/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salamane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 11:42:56 by salamane          #+#    #+#             */
/*   Updated: 2022/03/14 11:42:58 by salamane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	is_zero(t_philo	*data)
{
	if (data->time_to_die == 0 || data->time_to_eat == 0
		|| data->time_to_sleep == 0 || data->philos == 0
		|| data->mealcount == 0)
	{
		printf("Arg Error");
		return (0);
	}
	return (1);
}

int	cheaks(t_philo *info)
{
	time_t	c_time;
	int		i;

	while (1)
	{
		i = 0;
		c_time = ft_getutime();
		while (i < info->philos)
		{
			if (info->mealcount != -1
				&& info->mealcount == (info->meals * info->philos))
				return (0);
			if (c_time - info->lastmeal[i] > info->time_to_die)
			{		
				pthread_mutex_lock(info->turn);
				printf("%ld: %d is died\n", ft_getutime(), i + 1);
				return (0);
			}
			i++;
		}
	}
}

int	main(int argc, char **argv)
{
	pthread_t	*philo;
	int			i;
	t_philo		*info;

	info = NULL;
	if (argc == 5 || argc == 6)
		argc += 0;
	else
		return (0);
	info = (t_philo *)malloc(sizeof(t_philo));
	ft_init(argv, argc, &info);
	if (is_zero(info) == 0)
		return (0);
	i = 0;
	philo = malloc(sizeof(pthread_t) * info->philos);
	while (i < info->philos)
	{
		info->id = i;
		info->lastmeal[i] = ft_getutime();
		pthread_create(&philo[i], NULL, &philosopher, info);
		usleep(100);
		i++;
	}
	return (cheaks(info));
}
