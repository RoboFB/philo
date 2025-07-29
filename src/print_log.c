/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgohrig <rgohrig@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 14:00:47 by rgohrig           #+#    #+#             */
/*   Updated: 2025/07/29 15:15:11 by rgohrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_state(t_phil *phil)
{
	int					time_diff;
	static const char	*msg[] =
		{"is thinking", "is eating", "is sleeping", "died"};

	time_diff = get_time_diff_ms(phil->data);
	if (time_diff == ERROR)
		return (ERROR);
	pthread_mutex_lock(&phil->data->print_mtx);
	printf("%d %d %s\n", time_diff, phil->id, msg[*phil->state]);
	pthread_mutex_unlock(&phil->data->print_mtx);
	return (0);
}

int	print_fork(t_phil *phil)
{
	int					time_diff;

	time_diff = get_time_diff_ms(phil->data);
	if (time_diff == ERROR)
		return (ERROR);
	pthread_mutex_lock(&phil->data->print_mtx);
	printf("%d %d has taken a fork\n", time_diff, phil->id);
	pthread_mutex_unlock(&phil->data->print_mtx);
	return (0);
}
