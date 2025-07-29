/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgohrig <rgohrig@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 10:38:39 by rgohrig           #+#    #+#             */
/*   Updated: 2025/07/29 13:30:10 by rgohrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_arrays(t_philos *data)
{
	data->threads_philos = ft_calloc((data->total_philos + 1), sizeof(pthread_t));
	data->forks_mtx = ft_calloc((data->total_philos + 1), sizeof(pthread_mutex_t));
	data->states = ft_calloc((data->total_philos + 1), sizeof(t_philo_state));
	data->philos = ft_calloc((data->total_philos + 1), sizeof(t_phil));
	if (!data->forks_mtx || !data->threads_philos || !data->states || !data->philos)
		return (ERROR);
	return (0);
}

void	free_arrays(t_philos *data)
{
	if (data->threads_philos)
		free(data->threads_philos);
	if (data->forks_mtx)
		free(data->forks_mtx);
	if (data->states)
		free(data->states);
	if (data->philos)
		free(data->philos);
	data->threads_philos = NULL;
	data->forks_mtx = NULL;
	data->states = NULL;
	data->philos = NULL;
	return ;
}

int	init_phil_array(t_philos *data)
{
	int count;

	count = 0;
	while (count < data->total_philos)
	{
		if (count == 0)
			data->philos[count].fork_left = data->forks_mtx + data->total_philos - 1;
		else
			data->philos[count].fork_left = data->forks_mtx + count - 1;
		data->philos[count].fork_right = data->forks_mtx + count;
		data->philos[count].thread_phil = data->threads_philos + count;
		data->philos[count].status = data->states + count;
		data->philos[count].data = data;
		count++;
	}

	return (0);
}