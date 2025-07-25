/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgohrig <rgohrig@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 16:37:40 by rgohrig           #+#    #+#             */
/*   Updated: 2025/07/25 16:56:31 by rgohrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void start_philos(t_philos *data)
{
	int count;

	count = 0;
	while (count < data->total_philos)
	{
		pthread_create(&data->philo[count], NULL, (void *)single, NULL);
		count++;
	}
	

	return ;
}


void stop_philos(t_philos *data)
{
	int count;

	count = 0;
	while (count < data->total_philos)
	{
		pthread_join(data->philo[count], NULL);
		count++;
	}
	return ;
}