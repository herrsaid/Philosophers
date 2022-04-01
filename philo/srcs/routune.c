/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routune.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salamane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:56:08 by salamane          #+#    #+#             */
/*   Updated: 2022/03/30 15:56:10 by salamane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	sleping(int ts)
{
	time_t	start;

	start = ft_getutime();
	while (ft_getutime() - start < ts)
		usleep(500);
}

void	ft_continue(t_philo	*philo, pthread_mutex_t	*right,
			pthread_mutex_t	*left, int id)
{
	sleping(philo->time_to_eat);
	pthread_mutex_unlock(right);
	pthread_mutex_unlock(left);
	pthread_mutex_lock(philo->turn);
	printf("%ld: %d is sleeping\n", ft_getutime(), id + 1);
	pthread_mutex_unlock(philo->turn);
	sleping(philo->time_to_sleep);
	pthread_mutex_lock(philo->turn);
	printf("%ld: %d is thinking\n", ft_getutime(), id + 1);
	pthread_mutex_unlock(philo->turn);
}

void	*philosopher(void *arg)
{
	int				id;
	t_philo			*philo;
	pthread_mutex_t	*right;
	pthread_mutex_t	*left;

	philo = (t_philo *)arg;
	id = philo->id;
	right = philo->fork + id;
	left = philo->fork + ((id + 1) % philo->philos);
	while (1)
	{
		pthread_mutex_lock(right);
		pthread_mutex_lock(philo->turn);
		printf("%ld: %d has taken a fork\n", ft_getutime(), id + 1);
		pthread_mutex_unlock(philo->turn);
		pthread_mutex_lock(left);
		philo->lastmeal[id] = ft_getutime();
		pthread_mutex_lock(philo->turn);
		printf("%ld: %d is eating\n", ft_getutime(), id + 1);
		philo->mealcount++;
		pthread_mutex_unlock(philo->turn);
		ft_continue(philo, right, left, id);
	}
	return (NULL);
}
