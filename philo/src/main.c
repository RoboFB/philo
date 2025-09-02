/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgohrig <rgohrig@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:24:17 by rgohrig           #+#    #+#             */
/*   Updated: 2025/09/01 21:52:48 by rgohrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	h_data_arrays(t_data *data, int argc, char const *argv[])
{
	memset(data, 0, sizeof(t_data));
	gettimeofday(&data->start_time, NULL);
	if (parser(data, argc, argv) == ERROR)
	{
		write(2, "Error: Invalid arguments.\n", 26);
		return (ERROR);
	}
	if (calloc_arrays(data) == ERROR)
	{
		write(2, "Error: Failed to initialize arrays.\n", 36);
		free_arrays(data);
		return (ERROR);
	}
	fill_phil_pointers(data);
	fill_eat_timestamps(data);
	if (init_mtxs(data) == ERROR)
	{
		write(2, "Error: Failed to initialize mutexes.\n", 37);
		destroy_mtxs(data);
		free_arrays(data);
		return (ERROR);
	}
	return (0);
}

int	main(int argc, char const *argv[])
{
	t_data		data;

	if (h_data_arrays(&data, argc, argv) == ERROR)
		return (EXIT_FAILURE);
	create_philos(&data);
	monitor(&data);
	join_philos(&data);
	destroy_mtxs(&data);
	free_arrays(&data);
	return (EXIT_SUCCESS);
}
