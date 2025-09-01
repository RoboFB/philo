/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgohrig <rgohrig@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 14:41:14 by rgohrig           #+#    #+#             */
/*   Updated: 2025/09/01 15:33:01 by rgohrig          ###   ########.fr       */
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
	return (ms_time);
}

// R: (0)slept exact ms   -(1) slept less because stop simulation
int	sleep_exact_ms(t_data *data, int ms)
{
	int			time_ms;

	time_ms = get_time_diff_ms(&data->start_time);
	while ((get_time_diff_ms(&data->start_time) - time_ms) < ms-5)
	{
		if (check_stop_sim(data) == ERROR)
			return (ERROR);
		usleep(4500);
	}
	while ((get_time_diff_ms(&data->start_time) - time_ms) < ms-1)
	{
		if (check_stop_sim(data) == ERROR)
			return (ERROR);
		usleep(800);
	}
	while ((get_time_diff_ms(&data->start_time) - time_ms) < ms)
	{
		if (check_stop_sim(data) == ERROR)
			return (ERROR);
		usleep(100);
	}
	return (0);
}
