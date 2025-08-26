/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgohrig <rgohrig@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 14:00:47 by rgohrig           #+#    #+#             */
/*   Updated: 2025/08/26 19:23:25 by rgohrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	print_state(t_phil *phil, t_philo_state state)
// {
// 	int					time_ms;
// 	static const char	msg[3][12] =
// 		{"is thinking", "is eating", "is sleeping"};

// 	time_ms = get_time_diff_ms(&phil->data->start_time);
// 	pthread_mutex_lock(&phil->data->print_mtx);
// 	printf("%d %d %s\n", time_ms, phil->id, msg[state]);
// 	pthread_mutex_unlock(&phil->data->print_mtx);
// 	return (0);
// }

// void	print_fork(t_phil *phil)
// {
// 	int					time_ms;

// 	time_ms = get_time_diff_ms(&phil->data->start_time);
// 	pthread_mutex_lock(&phil->data->print_mtx);
// 	printf("%d %d has taken a fork\n", time_ms, phil->id);
// 	pthread_mutex_unlock(&phil->data->print_mtx);
// 	return ;
// }

// void	print_dead(t_phil *phil)
// {
// 	int					time_ms;

// 	time_ms = get_time_diff_ms(&phil->data->start_time);
// 	pthread_mutex_lock(&phil->data->print_mtx);
// 	printf("%d %d died\n", time_ms, phil->id);
// 	pthread_mutex_unlock(&phil->data->print_mtx);
// 	return ;
// }


// void	print_state(t_phil *phil, t_philo_state state)
// {
// 	int					time_ms;
// 	static const char	msg[3][12] =
// 		{"is thinking", "is eating", "is sleeping"};

// 	time_ms = get_time_diff_ms(&phil->data->start_time);
// 	pthread_mutex_lock(&phil->data->print_mtx);
// 	printf("%d %d %s\n", time_ms, phil->id, msg[state]);
// 	pthread_mutex_unlock(&phil->data->print_mtx);
// 	return (0);
// }

void	print_state(t_phil *phil, t_print_state state)
{
	int					time_ms;
	static const char	msg[5][17] =
		{"is thinking", "is eating", "is sleeping", "died", "has taken a fork"};

	time_ms = get_time_diff_ms(&phil->data->start_time);
	pthread_mutex_lock(&phil->data->print_mtx);
	printf("%d %d %s\n", time_ms, *phil->id, msg[state]);
	pthread_mutex_unlock(&phil->data->print_mtx);
	return ;
}
