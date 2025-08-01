/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgohrig <rgohrig@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 18:48:38 by rgohrig           #+#    #+#             */
/*   Updated: 2025/08/01 14:26:17 by rgohrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int init_all_mtx(t_philos *data)
{
	int count;

	count = 0;
	while (count < data->total_philos)
	{
		if (pthread_mutex_init(&data->forks_mtx[count], NULL) != 0)
			return (ERROR);
		count++;
	}
	if (pthread_mutex_init(&data->state_mtx, NULL) != 0)
		return (ERROR);
	if (pthread_mutex_init(&data->stop_sim_mtx, NULL) != 0)
		return (ERROR);
	if (pthread_mutex_init(&data->print_mtx, NULL) != 0)
		return (ERROR);
	if (pthread_mutex_init(&data->timestamp_eaten_mtx, NULL) != 0)
		return (ERROR);
	return (0);
}

void destroy_all_mtx(t_philos *data)
{
	int count;

	count = 0;
	while (count < data->total_philos)
	{
		if (pthread_mutex_destroy(&data->forks_mtx[count]) != 0)
		{
			// pthread_mutex_lock(&data->forks_mtx[count]);
			printf("DEBUGING Error: Failed to destroy mutex forks: %d\n", count);
			return ;
		}
		count++;
	}
	if (pthread_mutex_destroy(&data->state_mtx) != 0)
	{
		printf("DEBUGING Error: Failed to destroy mutex state\n");
		return ;
	}
	if (pthread_mutex_destroy(&data->stop_sim_mtx) != 0)
	{
		printf("DEBUGING Error: Failed to destroy mutex stop sim\n");
		return ;
	}
	if (pthread_mutex_destroy(&data->print_mtx) != 0)
	{
		printf("DEBUGING Error: Failed to destroy mutex print\n");
		return ;
	}
	if (pthread_mutex_destroy(&data->timestamp_eaten_mtx) != 0)
	{
		printf("DEBUGING Error: Failed to destroy mutex destroy\n");
		return ;
	}
	return ;
}

