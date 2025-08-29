/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgohrig <rgohrig@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:24:17 by rgohrig           #+#    #+#             */
/*   Updated: 2025/08/28 16:14:21 by rgohrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char const *argv[])
{
	t_data		data;

	memset(&data, 0, sizeof(t_data));
	(void)gettimeofday(&data.start_time, NULL);
	if (parser(argc, argv, &data) == ERROR)
	{
		printf("Error: Invalid arguments.\n");
		return (EXIT_FAILURE);
	}
	if (init_arrays(&data) == ERROR)
	{
		printf("Error: Failed to initialize arrays.\n");
		free_arrays(&data);
		return (EXIT_FAILURE);
	}
	init_phil_pointer(&data);
	init_data(&data);
	if (init_mtxs(&data) == ERROR)
	{
		printf("Error: Failed to initialize mutexes.\n");
		destroy_mtxs(&data);
		free_arrays(&data);
		return (EXIT_FAILURE);
	}
	create_philos(&data);
	monitor(&data);
	join_philos(&data);
	destroy_mtxs(&data);
	free_arrays(&data);
	return (EXIT_SUCCESS);
}
