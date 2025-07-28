/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgohrig <rgohrig@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:17:46 by rgohrig           #+#    #+#             */
/*   Updated: 2025/07/28 20:59:44 by rgohrig          ###   ########.fr       */
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


typedef enum e_philo_state
{
	THINKING,
	EATING,
	SLEEPING,
	DEAD
}				t_philo_state;

typedef struct s_philos
{
	// General data for all philosophers
	int					total_philos;
	int					die_ms;
	int					eat_ms;
	int					sleep_ms;
	int					max_eat;


	// Philosopher threads
	pthread_t			*philos; //M Array

	// mutexes array of all forks phi1 -> fork1
	pthread_mutex_t		*forks; // Malloc Array,  of locks

	// state of the philosopher
	t_philo_state		*state; // Malloc Array,  has lock
	pthread_mutex_t		state_access; // is lock


	bool				stop_simulation; // true if simulation should stop has lock
	pthread_mutex_t		stop_sim_access; // is lock

	pthread_mutex_t		print_access; // switch for printing is lock


}						t_philos;



/*
left_fork        right_fork
  last -> phi1 -> fork1
 fork1 -> phi2 -> fork2
 fork2 -> phi3 -> fork3
 fork3 -> phi4 -> fork4
 fork4 -> phi5 -> fork5
 ...      ...      ...

*/


// only poniters to acest the rigt one the momorz managment is in the main thread  
typedef struct s_phil
{
	pthread_t			*phil;

	pthread_mutex_t		*fork_left;
	pthread_mutex_t		*fork_right;

	pthread_mutex_t		*print;

	t_philos			*data; // pointer to the main data struct

}						t_phil;


// auto
size_t		ft_strlen(const char *s);
int			main(int argc, char const *argv[]);
int			parser(int argc, char const *argv[], t_philos *data);
void		single(t_philos *data);
void		start_philos(t_philos *data);
void		stop_philos(t_philos *data);

#endif
