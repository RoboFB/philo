/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgohrig <rgohrig@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:24:17 by rgohrig           #+#    #+#             */
/*   Updated: 2025/07/25 17:44:39 by rgohrig          ###   ########.fr       */
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

	data.philo = malloc((data.total_philos + 1) * sizeof(pthread_t));
	memset(data.philo, 0, (data.total_philos + 1) * sizeof(pthread_t));

	start_philos(&data);
	printf("test\n");

	stop_philos(&data);
	// pthread_join(, NULL);
	return (EXIT_SUCCESS);
}

