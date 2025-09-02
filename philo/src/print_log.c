/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgohrig <rgohrig@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 14:00:47 by rgohrig           #+#    #+#             */
/*   Updated: 2025/09/01 23:25:11 by rgohrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_print(t_phil *phil, t_print_state new_state)
{
	static const char	msg[5][17]
		= {"is thinking", "is eating", "is sleeping",
		"died", "has taken a fork"};

	pthread_mutex_lock(&phil->data->print_mtx);
	if (check_stop_sim(phil->data) == ERROR)
	{
		pthread_mutex_unlock(&phil->data->print_mtx);
		return (ERROR);
	}
	printf("%d %d %s\n",
		get_time_ms(&phil->data->start_time), *phil->id, msg[new_state]);
	pthread_mutex_unlock(&phil->data->print_mtx);
	return (0);
}

void	print_death(t_phil *phil)
{
	int					time_ms;

	pthread_mutex_lock(&phil->data->print_mtx);
	time_ms = get_time_ms(&phil->data->start_time);
	printf("%d %d died\n", time_ms, *phil->id);
	pthread_mutex_unlock(&phil->data->print_mtx);
	return ;
}
