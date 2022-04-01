/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salamane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:29:15 by salamane          #+#    #+#             */
/*   Updated: 2022/03/31 14:29:16 by salamane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	routune()
{
	int i = 0;
	while (1)
	{
		printf("said\n");
		usleep(1000);
		i++;
	}
	exit(1);
}
void	process()
{
	int pid;

	pid = fork();
	if (pid == 0)
		routune();
}

int main()
{
	int i = 0;

	while (i < 3)
	{
		process();
		i++;
	}
}
