/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salamane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 11:43:43 by salamane          #+#    #+#             */
/*   Updated: 2022/03/14 11:43:49 by salamane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H

# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	int				meals;
	int				id;
	int				philos;
	int				mealcount;
	time_t			*lastmeal;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*turn;
}					t_philo;

int		ft_atoi(char *str);
time_t	ft_getutime(void);
void	ft_init(char **argv, int argc, t_philo **info);
void	*philosopher(void *arg);

#endif