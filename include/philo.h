/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgohrig <rgohrig@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:17:46 by rgohrig           #+#    #+#             */
/*   Updated: 2025/07/25 16:45:19 by rgohrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>   // INT_MIN, INT_MAX
# include <pthread.h>  // pthreads and mutex
# include <stdbool.h>  // bool, true, false
# include <stdio.h>    // printf
# include <stdlib.h>   // malloc, free
# include <string.h>   // memset
# include <sys/time.h> // gettimeofday
# include <unistd.h>   // write, usleep

# define ERROR -1

typedef int		t_ms;

typedef struct s_philos
{
	int			total_philos;
	int			die_ms;
	int			eat_ms;
	int			sleep_ms;
	int			max_eat;

	pthread_t	*philo;

}				t_philos;

// auto
size_t		ft_strlen(const char *s);
int			main(int argc, char const *argv[]);
int			parser(int argc, char const *argv[], t_philos *data);
void		single(t_philos *data);
void		start_philos(t_philos *data);
void		stop_philos(t_philos *data);

#endif
