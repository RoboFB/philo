/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgohrig <rgohrig@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 18:48:38 by rgohrig           #+#    #+#             */
/*   Updated: 2025/09/01 16:26:53 by rgohrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// R: (0)ok  (-1)Error
int	init_mtxs(t_data *data)
{
	int		count;

	count = 0;
	while (count < data->total_philos)
	{
		if (pthread_mutex_init(&data->eat_mtxs[count], NULL) != 0)
			return (ERROR);
		if (pthread_mutex_init(&data->forks_mtxs[count], NULL) != 0)
			return (ERROR);
		count++;
	}
	if (pthread_mutex_init(&data->stop_sim_mtx, NULL) != 0)
		return (ERROR);
	if (pthread_mutex_init(&data->print_mtx, NULL) != 0)
		return (ERROR);
	return (0);
}

void	destroy_mtxs(t_data *data)
{
	int		count;

	count = 0;
	while (count < data->total_philos)
	{
		pthread_mutex_destroy(&data->eat_mtxs[count]);
		pthread_mutex_destroy(&data->forks_mtxs[count]);
		count++;
	}
	pthread_mutex_destroy(&data->stop_sim_mtx);
	pthread_mutex_destroy(&data->print_mtx);
	return ;
}
