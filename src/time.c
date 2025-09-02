/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgohrig <rgohrig@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 14:41:14 by rgohrig           #+#    #+#             */
/*   Updated: 2025/09/02 00:11:03 by rgohrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_time_ms(struct timeval *anchor)
{
	struct timeval	curr;

	gettimeofday(&curr, NULL);
	return ((curr.tv_sec - anchor->tv_sec) * 1000
		+ (curr.tv_usec - anchor->tv_usec) / 1000);
}

// R: (0)slept exact ms   -(1) slept less because stop simulation
int	sleep_exact_ms(t_data *data, int sleep_ms)
{
	int			start_ms;
	int			remaining_ms;

	start_ms = get_time_ms(&data->start_time);
	while (1)
	{
		remaining_ms = sleep_ms - (get_time_ms(&data->start_time) - start_ms);
		if (remaining_ms >= 5)
		{
			if (check_stop_sim(data) == ERROR)
				return (ERROR);
			usleep(3000);
		}
		if (remaining_ms >= 2)
		{
			if (check_stop_sim(data) == ERROR)
				return (ERROR);
			usleep(500);
		}
		else if (remaining_ms >= 1)
			usleep(100);
		else
			break ;
	}
	return (0);
}
