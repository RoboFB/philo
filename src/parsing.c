/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgohrig <rgohrig@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 12:06:44 by rgohrig           #+#    #+#             */
/*   Updated: 2025/09/01 21:16:56 by rgohrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// R: num of converted chars or -1 on error | converts str to number
static int	h_strict_atoi(const char *nptr, int *result)
{
	long int	num;
	int			len;
	int			negative;

	num = 0;
	len = 0;
	negative = 1;
	if (!nptr || !result)
		return (ERROR);
	if (*nptr == '-')
	{
		negative = -1;
		nptr++;
		len++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		num = num * 10 + (*nptr - '0') * negative;
		if (num < INT_MIN || num > INT_MAX)
			return (ERROR);
		nptr++;
		len++;
	}
	*result = (int)num;
	return (len);
}

// R: (0)ok  (-1)Error   | parses one argument
static int	h_one_arg(char const *input, int min, int max, int *out)
{
	if (input == NULL || *input == '\0')
		return (ERROR);
	if (h_strict_atoi(input, out) != (int)ft_strlen(input))
		return (ERROR);
	if (*out < min || *out > max)
		return (ERROR);
	return (0);
}

// R: (0)ok  (-1)Error   | parses argc and argv
int	parser(t_data *data, int argc, char const *argv[])
{
	if (argc != 5 && argc != 6)
		return (ERROR);
	if ((h_one_arg(argv[1], 1, 200, &data->total_philos) == ERROR)
		|| (h_one_arg(argv[2], 0, INT_MAX, &data->die_ms) == ERROR)
		|| (h_one_arg(argv[3], 0, INT_MAX, &data->eat_ms) == ERROR)
		|| (h_one_arg(argv[4], 0, INT_MAX, &data->sleep_ms) == ERROR))
		return (ERROR);
	if (argc == 5)
		data->max_eat_count = INT_MAX;
	else if (h_one_arg(argv[5], 0, INT_MAX, &data->max_eat_count) == ERROR)
		return (ERROR);
	return (0);
}
