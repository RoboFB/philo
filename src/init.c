/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgohrig <rgohrig@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 10:38:39 by rgohrig           #+#    #+#             */
/*   Updated: 2025/08/26 18:01:36 by rgohrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_arrays(t_data *data)
{
	data->threads_philos = ft_calloc((data->total_philos), sizeof(
				pthread_t));
	data->philos = ft_calloc((data->total_philos), sizeof(
				t_phil));
	data->ids = ft_calloc((data->total_philos), sizeof(
				int));
	data->eat_timestamps = ft_calloc((data->total_philos), sizeof(
				struct timeval));
	data->eat_counts = ft_calloc((data->total_philos), sizeof(
				int));
	data->eat_mtxs = ft_calloc((data->total_philos), sizeof(
				pthread_mutex_t));
	data->forks = ft_calloc((data->total_philos), sizeof(
				bool));
	data->forks_mtxs = ft_calloc((data->total_philos), sizeof(
				pthread_mutex_t));

	if (!data->threads_philos
		|| !data->philos
		|| !data->ids
		|| !data->eat_timestamps
		|| !data->eat_counts
		|| !data->eat_mtxs
		|| !data->forks
		|| !data->forks_mtxs)
		return (ERROR);
	return (0);
}

void	free_arrays(t_data *data)
{
	if (data->threads_philos)
		free(data->threads_philos);
	if (data->philos)
		free(data->philos);
	if (data->ids)
		free(data->ids);
	if (data->eat_timestamps)
		free(data->eat_timestamps);
	if (data->eat_counts)
		free(data->eat_counts);
	if (data->eat_mtxs)
		free(data->eat_mtxs);
	if (data->forks)
		free(data->forks);
	if (data->forks_mtxs)
		free(data->forks_mtxs);
	data->threads_philos = NULL;
	data->philos = NULL;
	data->ids = NULL;
	data->eat_timestamps = NULL;
	data->eat_counts = NULL;
	data->eat_mtxs = NULL;
	data->forks = NULL;
	data->forks_mtxs = NULL;
	return ;
}

void init_data(t_data *data)
{
	int		count;

	count = 0;
	while (count < data->total_philos)
	{
		data->ids[count] = count + 1;
		ft_memcpy(&data->eat_timestamps[count], &data->start_time, sizeof(struct timeval));
		count++;
	}
	return ;
}

void	init_phil_pointer(t_data *data)
{
	int		count;

	count = 0;
	while (count < data->total_philos)
	{
		data->philos[count].id = data->ids + count;
		data->philos[count].eat_timestamp = data->eat_timestamps + count;
		data->philos[count].eat_count = data->eat_counts + count;
		data->philos[count].eat_mtx = data->eat_mtxs + count;
		if (count == 0)
			data->philos[count].fork_left = data->forks + data->total_philos - 1;
		else
			data->philos[count].fork_left = data->forks + count - 1;
		if (count == 0)
			data->philos[count].fork_left_mtx = data->forks_mtxs + data->total_philos - 1;
		else
			data->philos[count].fork_left_mtx = data->forks_mtxs + count - 1;
		data->philos[count].fork_right = data->forks + count;
		data->philos[count].fork_right_mtx = data->forks_mtxs + count;
		data->philos[count].data = data;
		count++;
	}
	return ;
}
