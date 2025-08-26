/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgohrig <rgohrig@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 15:01:55 by rgohrig           #+#    #+#             */
/*   Updated: 2025/08/26 17:47:18 by rgohrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int dead_check(t_data *data)
{
	int				count;
	struct timeval	curr;

	(void)gettimeofday(&curr, NULL);

	pthread_mutex_lock(&data->eat_mtxs);
	count = 0;
	while (count < data->total_philos)
	{
		if (data->die_ms < get_time_diff_2_ms(&data->eat_timestamps[count], &curr))
		{
			pthread_mutex_unlock(&data->eat_mtxs);
			pthread_mutex_lock(&data->stop_sim_mtx);
			data->stop_simulation = true;
			pthread_mutex_unlock(&data->stop_sim_mtx);
			print_dead(&data->philos[count]);
			return (1);
		}
		count++;
	}
	pthread_mutex_unlock(&data->eat_mtxs);
	return (0);
}

void monitor(t_data *data)
{
	while (dead_check(data) == 0)
	{
		if (sleep_exact_ms(data, 1) == ERROR)
			return ;
	}
	return ;
}