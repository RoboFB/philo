/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgohrig <rgohrig@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 15:01:55 by rgohrig           #+#    #+#             */
/*   Updated: 2025/09/01 16:34:21 by rgohrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_stop_sim(t_data *data)
{
	// pthread_mutex_lock(&data->print_mtx);// ?
	pthread_mutex_lock(&data->stop_sim_mtx);
	data->stop_simulation = true;
	pthread_mutex_unlock(&data->stop_sim_mtx);
	// pthread_mutex_unlock(&data->print_mtx);// ?
	return ;
}

// R: (0)Normal  (-1)stop sim
int	check_stop_sim(t_data *data)
{
	int		return_value;

	return_value = 0;
	pthread_mutex_lock(&data->stop_sim_mtx);
	if (data->stop_simulation)
		return_value = ERROR;
	pthread_mutex_unlock(&data->stop_sim_mtx);
	return (return_value);
}

// R: (0)ok  (1)stop dead   (2)stop all eaten
static int	h_stop_check(t_data *data)
{
	int				idx;
	int				finished_melees;
	struct timeval	timestamp;

	finished_melees = 0;
	idx = 0;
	while (idx < data->total_philos)
	{
		pthread_mutex_lock(&data->eat_mtxs[idx]);
		(void)gettimeofday(&timestamp, NULL);
		if (get_time_diff_2_ms(&data->eat_timestamps[idx], &timestamp)
			>= data->die_ms)
			return (set_stop_sim(data), print_death(&data->philos[idx]),
				pthread_mutex_unlock(&data->eat_mtxs[idx]), 1);
		if (data->eat_counts[idx] >= data->max_eat_count)
			finished_melees++;
		pthread_mutex_unlock(&data->eat_mtxs[idx]);
		idx++;
	}
	if (finished_melees == data->total_philos)
		return (set_stop_sim(data), 2);
	return (0);
}

void	monitor(t_data *data)
{
	while (h_stop_check(data) == 0)
		usleep(100);
	return ;
}
