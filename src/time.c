/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgohrig <rgohrig@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 14:41:14 by rgohrig           #+#    #+#             */
/*   Updated: 2025/08/01 16:27:53 by rgohrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_time_diff_ms(struct timeval *anchor)
{
	struct timeval	curr;

	if (gettimeofday(&curr, NULL) == ERROR)
	{
		printf("Error: gettimeofday failed\n");
		return (ERROR);
	}
	return ((curr.tv_sec - anchor->tv_sec) * 1000
		 + (curr.tv_usec - anchor->tv_usec) / 1000);
}


int	get_time_diff_2_ms(struct timeval *anchor, struct timeval *curr)
{
	int		ms_time;

	ms_time = (curr->tv_sec - anchor->tv_sec) * 1000 + (curr->tv_usec - anchor->tv_usec) / 1000;
	if(ms_time < 0)
		ms_time *= -1;
	return (ms_time);
}



// R: (0)slept exact ms   -(1) slept less because stop simulation or error gettimeofday
int	sleep_exact_ms(t_philos *data, int ms)
{
	struct timeval	start;

	if (gettimeofday(&start, NULL) == ERROR)
	{
		printf("Error: gettimeofday failed\n");
		return (ERROR);
	}
	while (get_time_diff_ms(&start) < ms)
	{
		pthread_mutex_lock(&data->stop_sim_mtx);
		if (data->stop_simulation)
		{
			pthread_mutex_unlock(&data->stop_sim_mtx);
			return (ERROR);
		}
		pthread_mutex_unlock(&data->stop_sim_mtx);
		usleep(300);//0.3 ms
	}
	return (0);
}
