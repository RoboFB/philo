/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgohrig <rgohrig@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 15:01:55 by rgohrig           #+#    #+#             */
/*   Updated: 2025/08/26 19:23:57 by rgohrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void h_stop_sim(t_data *data)
{
	pthread_mutex_lock(&data->stop_sim_mtx);
	data->stop_simulation = true;
	pthread_mutex_unlock(&data->stop_sim_mtx);
	return ;
}

// R: (0)ok  (1)stop dead   (2)stop all eaten
static int h_stop_check(t_data *data)
{
	int				idx;
	int				finished_melees;
	struct timeval	timestamp;

	(void)gettimeofday(&timestamp, NULL);
	finished_melees = 0;
	idx = 0;
	while (idx < data->total_philos)
	{
		pthread_mutex_lock(&data->eat_mtxs[idx]);
		if (get_time_diff_2_ms(&data->eat_timestamps[idx], &timestamp) > data->die_ms)
		{
			h_stop_sim(data);
			pthread_mutex_unlock(&data->eat_mtxs[idx]);
			print_state(&data->philos[idx], PR_DEAD);
			return (1);
		}
		if (data->eat_counts[idx] <= data->max_eat_count)
			finished_melees++;
		pthread_mutex_unlock(&data->eat_mtxs[idx]);
		idx++;
	}
	if (finished_melees == data->total_philos)
		return (h_stop_sim(data), 2);
	return (0);
}

void monitor(t_data *data)
{
	while (h_stop_check(data) == 0)
		usleep(500);
	return ;
}
