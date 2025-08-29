/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgohrig <rgohrig@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 14:41:14 by rgohrig           #+#    #+#             */
/*   Updated: 2025/08/29 16:05:41 by rgohrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_time_diff_ms(struct timeval *anchor)
{
	struct timeval	curr;

	(void)gettimeofday(&curr, NULL);
	return ((curr.tv_sec - anchor->tv_sec) * 1000
		 + (curr.tv_usec - anchor->tv_usec) / 1000);
}

int	get_time_diff_2_ms(struct timeval *anchor, struct timeval *curr)
{
	int		ms_time;

	ms_time = (curr->tv_sec - anchor->tv_sec) * 1000 + (curr->tv_usec - anchor->tv_usec) / 1000;
	// if(ms_time < 0)
	// 	ms_time *= -1;
	return (ms_time);
}

// R: (0)slept exact ms   -(1) slept less because stop simulation
int	sleep_exact_ms(t_data *data, int ms)
{
	struct timeval	start;

	(void)gettimeofday(&start, NULL);
	// usleep(ms *(1000 - 200)); // sleep most of the time
	while (get_time_diff_ms(&start) < ms)
	{
		if (check_stop_sim(data) == ERROR)
			return (ERROR);
		usleep(30);//0.1 ms
	}
	// pthread_mutex_lock(&data->print_mtx);
	// printf("DEBUGGING: slept %d\n", get_time_diff_ms(&start));
	// pthread_mutex_unlock(&data->print_mtx);
	return (0);
}
