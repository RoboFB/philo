/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgohrig <rgohrig@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:17:46 by rgohrig           #+#    #+#             */
/*   Updated: 2025/07/29 13:34:13 by rgohrig          ###   ########.fr       */
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
	THINKING = 0, // init value
	EATING,
	SLEEPING,
	DEAD
}				t_philo_state;

typedef struct s_phil t_phil;

typedef struct s_philos
{
	// General data for all philosophers
	int					total_philos;
	int					die_ms;
	int					eat_ms;
	int					sleep_ms;
	int					max_eat;

	pthread_t			*threads_philos; //Malloc Array
	t_phil				*philos; // Malloc Array

	// HAS lock
	t_philo_state		*states; // Malloc Array

	bool				stop_simulation; // true if simulation should stop has lock

	// IS lock
	pthread_mutex_t		*forks_mtx; // Malloc Array

	pthread_mutex_t		state_mtx;
	pthread_mutex_t		stop_sim_mtx;
	pthread_mutex_t		print_mtx;


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


// only pointers -> memory management in the main thread
typedef struct s_phil
{
	pthread_t			*thread_phil;

	t_philo_state		*status;
	pthread_mutex_t		*fork_left;
	pthread_mutex_t		*fork_right;


	t_philos			*data;

}						t_phil;


// auto
void		*ft_calloc(size_t nelem, size_t elsize);
size_t		ft_strlen(const char *s);
int			init_arrays(t_philos *data);
void		free_arrays(t_philos *data);
int			init_phil_array(t_philos *data);
int			main(int argc, char const *argv[]);
int			init_all_mtx(t_philos *data);
void		destroy_all_mtx(t_philos *data);
int			parser(int argc, char const *argv[], t_philos *data);
void		single(t_philos *data);
void		create_philos(t_philos *data);
void		join_philos(t_philos *data);

#endif
