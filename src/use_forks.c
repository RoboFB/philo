/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_forks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgohrig <rgohrig@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 17:11:02 by rgohrig           #+#    #+#             */
/*   Updated: 2025/09/01 16:05:12 by rgohrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// R: (0)Normal  (-1)stop sim
int	take_print_fork(t_phil *phil, pthread_mutex_t *fork_mtx, bool *fork)
{
	while (1)
	{
		pthread_mutex_lock(fork_mtx);
		if (check_stop_sim(phil->data) == ERROR)
			return (pthread_mutex_unlock(fork_mtx), ERROR);
		if (*fork == false)
		{
			*fork = true;
			pthread_mutex_unlock(fork_mtx);
			break ;
		}
		else
		{
			pthread_mutex_unlock(fork_mtx);
		}
		usleep(250);
	}
	return (check_print(phil, PR_FORK));
}

// R: void
void	release_forks(t_phil *phil)
{
	pthread_mutex_lock(phil->fork_right_mtx);
	*phil->fork_right = false;
	pthread_mutex_unlock(phil->fork_right_mtx);
	pthread_mutex_lock(phil->fork_left_mtx);
	*phil->fork_left = false;
	pthread_mutex_unlock(phil->fork_left_mtx);
	return ;
}
