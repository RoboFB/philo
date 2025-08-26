/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgohrig <rgohrig@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:17:46 by rgohrig           #+#    #+#             */
/*   Updated: 2025/08/26 19:24:23 by rgohrig          ###   ########.fr       */
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


typedef enum e_print_state
{
	PR_THINKING = 0, // init value
	PR_EATING = 1,
	PR_SLEEPING = 2,
	PR_DEAD = 3,
	PR_FORK = 4
}				t_print_state;

typedef struct s_phil t_phil;


// prof of concept vielleicht?
// typedef struct s_save_x
// {
// 	pthread_mutex_t		mtx;
// 	int					value;

// }						t_save_x;


typedef struct s_data
{
	// General data for all philosophers
	int					total_philos;
	int					die_ms;
	int					eat_ms;
	int					sleep_ms;
	int					max_eat_count;
	struct timeval		start_time;



	// General data for all philos
	pthread_t			*threads_philos; //Malloc Array
	t_phil				*philos; // Malloc Array


	// DATA for single philos

	// HAS No lock
	int					*ids; // Malloc Array                init: data

	
	// HAS lock + lock
	struct timeval		*eat_timestamps; // Malloc Array      init: data
	int					*eat_counts; // Malloc Array         (init): 0
	pthread_mutex_t		*eat_mtxs; // Malloc Array           init: mtx
	
	bool				*forks; // Malloc Array               (init): 0/false/not taken
	pthread_mutex_t		*forks_mtxs; // Malloc Array          init: mtx
	
	bool				stop_simulation; // true if simulation should stop has lock    (init:) 0/false
	pthread_mutex_t		stop_sim_mtx; //                    init: mtx

	pthread_mutex_t		print_mtx; //                       init: mtx


}						t_data;



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

	// Has no Lock
	int					*id;
	
	// HAS lock + lock
	struct timeval		*eat_timestamp;
	int					*eat_count;
	pthread_mutex_t		*eat_mtx;

	bool				*fork_left;
	pthread_mutex_t		*fork_left_mtx;

	bool				*fork_right;
	pthread_mutex_t		*fork_right_mtx;

	// back link
	t_data				*data;

}						t_phil;


// auto
void		*ft_calloc(size_t nelem, size_t elsize);
void		*ft_memcpy(void *dst, const void *src, size_t n);
size_t		ft_strlen(const char *s);
int			init_arrays(t_data *data);
void		free_arrays(t_data *data);
void		init_data(t_data *data);
void		init_phil_pointer(t_data *data);
int			main(int argc, char const *argv[]);
void		monitor(t_data *data);
int			init_mtxs(t_data *data);
void		destroy_mtxs(t_data *data);
int			parser(int argc, char const *argv[], t_data *data);
void		print_state(t_phil *phil, t_print_state state);
int			change_print_state(t_phil *phil, t_print_state new_state);
int			take_print_fork(t_phil *phil, pthread_mutex_t *fork);
void		*single(void *phil_arg);
void		create_philos(t_data *data);
void		join_philos(t_data *data);
int			get_time_diff_ms(struct timeval *anchor);
int			get_time_diff_2_ms(struct timeval *anchor, struct timeval *curr);
int			sleep_exact_ms(t_data *data, int ms);

#endif
