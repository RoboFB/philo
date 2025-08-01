/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgohrig <rgohrig@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 16:37:40 by rgohrig           #+#    #+#             */
/*   Updated: 2025/07/31 15:00:48 by rgohrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void create_philos(t_philos *data)
{
	int count;

	count = 0;
	while (count < data->total_philos)
	{
		pthread_create(&data->threads_philos[count], NULL, single, &data->philos[count]);
		count++;
	}

	return ;
}

void join_philos(t_philos *data)
{
	int count;

	count = 0;
	while (count < data->total_philos)
	{
		pthread_join(data->threads_philos[count], NULL);
		count++;
	}
	return ;
}