/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgohrig <rgohrig@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 16:40:30 by rgohrig           #+#    #+#             */
/*   Updated: 2025/08/26 17:47:56 by rgohrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	change_print_state(t_phil *phil, t_philo_state new_state)
{
	int	return_value;
	
	return_value = 0;
	pthread_mutex_lock(&phil->data->stop_sim_mtx);
	if (phil->data->stop_simulation)
		return_value = ERROR;
	pthread_mutex_unlock(&phil->data->stop_sim_mtx);

	if (return_value == 0)
	{
		print_state(phil);
	}
	return (return_value);
}


int	take_print_fork(t_phil *phil, pthread_mutex_t *fork)
{
	int	return_value;
	
	return_value = 0;
	pthread_mutex_lock(&phil->data->stop_sim_mtx);
	if (phil->data->stop_simulation)
		return_value = ERROR;
	pthread_mutex_unlock(&phil->data->stop_sim_mtx);

	if (return_value == 0)
	{
		pthread_mutex_lock(fork);
		print_fork(phil);
	}
	return (return_value);
}


static int	h_think(t_phil *phil)
{
	if (change_print_state(phil, THINKING) == ERROR)
		return (ERROR);
	if (phil->id % 2 == 0)
	{
		if (phil->eat_count == 0
			&& sleep_exact_ms(phil->data, (phil->data->eat_ms) / 2) == ERROR)
			return (ERROR);
		if (take_print_fork(phil, phil->fork_left_mtx) == ERROR
			|| take_print_fork(phil, phil->fork_right_mtx) == ERROR)
			return (ERROR);
	}
	else
	{
		if (take_print_fork(phil, phil->fork_right_mtx) == ERROR
		|| take_print_fork(phil, phil->fork_left_mtx) == ERROR)
		return (ERROR);
	}
	return (0);
}
static int	h_eat(t_phil *phil)
{
	int	return_value;

	if (change_print_state(phil, EATING) == ERROR)
		return (ERROR);
	return_value = 0;
	pthread_mutex_lock(&phil->data->eat_mtxs);
	(void)gettimeofday(phil->eat_timestamp, NULL);
	pthread_mutex_unlock(&phil->data->eat_mtxs);
	if (sleep_exact_ms(phil->data, phil->data->eat_ms) == ERROR)
		return_value = ERROR;
	pthread_mutex_unlock(phil->fork_right_mtx);
	pthread_mutex_unlock(phil->fork_left_mtx);
	return (return_value);
}
static int	h_sleep(t_phil *phil)
{
	if (change_print_state(phil, SLEEPING) == ERROR)
		return (ERROR);
	if (sleep_exact_ms(phil->data, phil->data->sleep_ms) == ERROR)
		return (ERROR);
	return (0);
}

// todo error handeling returns
void	*single(void *phil_arg)
{
	t_phil	*phil;

	phil = (t_phil *)phil_arg;
	while (phil->eat_count < phil->data->max_eat_count)
	{
		if (h_think(phil) == ERROR
			|| h_eat(phil) == ERROR
			|| h_sleep(phil) == ERROR)
			return (NULL);
		phil->eat_count++;
	}
	if (phil->eat_count == phil->data->max_eat_count) // needs better handeling of braking if has finsed eating mab make it to enum with SOTP_EAT STOP_DEAD
	{
		pthread_mutex_lock(&phil->data->stop_sim_mtx);
		phil->data->stop_simulation = true;
		pthread_mutex_unlock(&phil->data->stop_sim_mtx);
	}
	return (NULL);
}
