/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgohrig <rgohrig@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 14:41:14 by rgohrig           #+#    #+#             */
/*   Updated: 2025/07/29 14:43:35 by rgohrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_time_diff_ms(t_philos *data)
{
	struct timeval	new;

	if (gettimeofday(&new, NULL) == ERROR)
	{
		printf("Error: gettimeofday failed\n");
		return (ERROR);
	}
	return ((new.tv_sec - data->start_time.tv_sec) * 1000
		 + (new.tv_usec - data->start_time.tv_usec) / 1000);
}
