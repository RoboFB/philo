/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgohrig <rgohrig@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:24:17 by rgohrig           #+#    #+#             */
/*   Updated: 2025/07/28 19:22:33 by rgohrig          ###   ########.fr       */
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

	data.philos = malloc((data.total_philos + 1) * sizeof(pthread_t));
	memset(data.philos, 0, (data.total_philos + 1) * sizeof(pthread_t));

	data.forks = malloc((data.total_philos + 1) * sizeof(pthread_mutex_t));
	memset(data.forks, 0, (data.total_philos + 1) * sizeof(pthread_mutex_t));

	init_forks(data.forks, data.total_philos);

	start_philos(&data);
	printf("test\n");

	stop_philos(&data);
	// pthread_join(, NULL);
	return (EXIT_SUCCESS);
}

