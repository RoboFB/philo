/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgohrig <rgohrig@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 15:01:55 by rgohrig           #+#    #+#             */
/*   Updated: 2025/08/01 14:32:40 by rgohrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int dead_check(t_philos *data)
{
	int				count;
	struct timeval	curr;

	if (gettimeofday(&curr, NULL) == ERROR)
	{
		printf("Error: gettimeofday failed\n");
		return (ERROR);
	}
	pthread_mutex_lock(&data->timestamp_eaten_mtx);
	count = 0;
	while (count < data->total_philos)
	{
		if (data->die_ms < get_time_diff_2_ms(&data->timestamp_eaten[count], &curr))
		{
			pthread_mutex_unlock(&data->timestamp_eaten_mtx);
			pthread_mutex_lock(&data->stop_sim_mtx);
			data->stop_simulation = true;
			pthread_mutex_unlock(&data->stop_sim_mtx);
			print_dead(&data->philos[count]);
			return (1);
		}
		count++;
	}
	pthread_mutex_unlock(&data->timestamp_eaten_mtx);
	return (0);
}

void monitor(t_philos *data)
{
	while (dead_check(data) == 0)
	{
		if (sleep_exact_ms(data, 1) == ERROR)
			return ;
	}
	return ;
}