/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgohrig <rgohrig@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 16:40:30 by rgohrig           #+#    #+#             */
/*   Updated: 2025/09/01 16:23:15 by rgohrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// R: (0)Normal  (-1)stop sim
static int	h_think(t_phil *phil)
{
	return (check_print(phil, PR_THINKING));
}

// R: (0)Normal  (-1)stop sim
static int	h_forks(t_phil *phil)
{
	pthread_mutex_lock(phil->eat_mtx);
	if (*phil->eat_count == 0 && *phil->id % 2 == 0)
		usleep(5000);
	pthread_mutex_unlock(phil->eat_mtx);
	if (*phil->id % 2 == 0 && phil->data->total_philos % 2 == 0)
	{
		if (take_print_fork(
				phil, phil->fork_left_mtx, phil->fork_left) == ERROR
			|| take_print_fork(
				phil, phil->fork_right_mtx, phil->fork_right) == ERROR)
			return (ERROR);
	}
	else
	{
		if (take_print_fork(
				phil, phil->fork_right_mtx, phil->fork_right) == ERROR
			|| take_print_fork(
				phil, phil->fork_left_mtx, phil->fork_left) == ERROR)
			return (ERROR);
	}
	return (0);
}

// R: (0)Normal  (-1)stop sim
static int	h_eat(t_phil *phil)
{
	pthread_mutex_lock(phil->eat_mtx);
	if (check_stop_sim(phil->data) == ERROR)
		return (pthread_mutex_unlock(phil->eat_mtx), ERROR);
	(void)gettimeofday(phil->eat_timestamp, NULL);
	pthread_mutex_unlock(phil->eat_mtx);
	if (check_print(phil, PR_EATING) == ERROR)
		return (ERROR);
	if (sleep_exact_ms(phil->data, phil->data->eat_ms) == ERROR)
		return (ERROR);
	release_forks(phil);
	pthread_mutex_lock(phil->eat_mtx);
	if (check_stop_sim(phil->data) == ERROR)
		return (pthread_mutex_unlock(phil->eat_mtx), ERROR);
	(*phil->eat_count)++;
	pthread_mutex_unlock(phil->eat_mtx);
	return (0);
}

// R: (0)Normal  (-1)stop sim
static int	h_sleep(t_phil *phil)
{
	if (check_print(phil, PR_SLEEPING) == ERROR)
		return (ERROR);
	if (sleep_exact_ms(phil->data, phil->data->sleep_ms) == ERROR)
		return (ERROR);
	return (0);
}

// R: NULL
void	*single(void *phil_arg)
{
	t_phil	*phil;

	phil = (t_phil *)phil_arg;
	while (1)
		if (h_think(phil) == ERROR
			|| h_forks(phil) == ERROR
			|| h_eat(phil) == ERROR
			|| h_sleep(phil) == ERROR)
			break ;
	return (NULL);
}
