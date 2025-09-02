/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgohrig <rgohrig@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:17:46 by rgohrig           #+#    #+#             */
/*   Updated: 2025/09/02 16:42:19 by rgohrig          ###   ########.fr       */
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

typedef struct s_phil	t_phil;
typedef int				t_ms;

typedef enum e_print_state
{
	PR_THINKING = 0,
	PR_EATING = 1,
	PR_SLEEPING = 2,
	PR_DEAD = 3,
	PR_FORK = 4
}				t_print_state;

// all the data for the simulation
typedef struct s_data
{
	int					total_philos;
	int					die_ms;
	int					eat_ms;
	int					sleep_ms;
	int					max_eat_count;
	struct timeval		start_time;

	pthread_t			*threads_philos;
	t_phil				*philos;
	int					*ids;

	struct timeval		*eat_timestamps;
	int					*eat_counts;
	pthread_mutex_t		*eat_mtxs;

	bool				*forks;
	pthread_mutex_t		*forks_mtxs;

	bool				stop_simulation;
	pthread_mutex_t		stop_sim_mtx;

	pthread_mutex_t		print_mtx;

}						t_data;

// only pointers -> memory management in the main thread
typedef struct s_phil
{
	int					*id;

	struct timeval		*eat_timestamp;
	int					*eat_count;
	pthread_mutex_t		*eat_mtx;

	bool				*fork_left;
	pthread_mutex_t		*fork_left_mtx;

	bool				*fork_right;
	pthread_mutex_t		*fork_right_mtx;

	t_data				*data;

}						t_phil;

void		*ft_calloc(size_t nelem, size_t elsize);
void		*ft_memcpy(void *dst, const void *src, size_t n);
size_t		ft_strlen(const char *s);

int			calloc_arrays(t_data *data);
void		free_arrays(t_data *data);
void		fill_eat_timestamps(t_data *data);
void		fill_phil_pointers(t_data *data);

int			check_stop_sim(t_data *data);
void		monitor(t_data *data);
int			init_mtxs(t_data *data);
void		destroy_mtxs(t_data *data);
int			parser(t_data *data, int argc, char const *argv[]);
int			check_print(t_phil *phil, t_print_state new_state);
void		print_death(t_phil *phil);
void		*single(void *phil_arg);
void		create_philos(t_data *data);
void		join_philos(t_data *data);
int			get_time_ms(struct timeval *anchor);
int			sleep_exact_ms(t_data *data, int ms);
int			take_print_fork(
				t_phil *phil, pthread_mutex_t *fork_mtx, bool *fork);
void		release_forks(t_phil *phil);

#endif
