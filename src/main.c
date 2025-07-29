/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgohrig <rgohrig@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:24:17 by rgohrig           #+#    #+#             */
/*   Updated: 2025/07/29 13:31:32 by rgohrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char const *argv[])
{
	t_philos		data;


	memset(&data, 0, sizeof(t_philos));
	if (parser(argc, argv, &data) == ERROR)
	{
		printf("Error: Invalid arguments.\n");
		return (EXIT_FAILURE);
	}

	if (init_arrays(&data) == ERROR || init_phil_array(&data) == ERROR)
	{
		printf("Error: Failed to initialize arrays.\n");
		free_arrays(&data);
		return (EXIT_FAILURE);
	}
	if (init_all_mtx(&data) == ERROR)
	{
		printf("Error: Failed to initialize forks.\n");
		destroy_all_mtx(&data);
		free_arrays(&data);
		return (EXIT_FAILURE);
	}

	create_philos(&data);
	printf("Runing\n");
	join_philos(&data);

	destroy_all_mtx(&data);
	free_arrays(&data);
	return (EXIT_SUCCESS);
}

