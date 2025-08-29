/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgohrig <rgohrig@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 16:37:40 by rgohrig           #+#    #+#             */
/*   Updated: 2025/08/28 12:14:10 by rgohrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void create_philos(t_data *data)
{
	int count;

	count = 0;
	while (count < data->total_philos)
	{
		if (pthread_create(&data->threads_philos[count], NULL, single, &data->philos[count]))
			write(2, "DEBUGING: ERROR: thread create failed\n", 39);
		count++;
	}
	return ;
}

void join_philos(t_data *data)
{
	int count;

	count = 0;
	while (count < data->total_philos)
	{
		if (pthread_join(data->threads_philos[count], NULL))
			write(2, "DEBUGING: ERROR: thread join failed\n", 37);
		count++;
	}
	return ;
}