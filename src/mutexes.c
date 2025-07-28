/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgohrig <rgohrig@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 18:48:38 by rgohrig           #+#    #+#             */
/*   Updated: 2025/07/28 19:32:56 by rgohrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void init_forks(t_philos *data)
{
	int count;

	count = 0;
	while (count < data->total_philos)
	{
		pthread_mutex_init(&data->forks[count], NULL);
		count++;
	}

	return ;
}


void destroy_forks(t_philos *data)
{
	int count;

	count = 0;
	while (count < data->total_philos)
	{
		pthread_mutex_destroy(&data->forks[count]);
		count++;
	}

	return ;
}

void init_print(t_philos *data)
{
	pthread_mutex_init(&data->print, NULL);
	return ;
}

void destroy_print(t_philos *data)
{
	pthread_mutex_destroy(&data->print);
	return ;
}
