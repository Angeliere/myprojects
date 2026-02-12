/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschweit <aschweit@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:30:00 by aschweit          #+#    #+#             */
/*   Updated: 2026/02/12 13:43:47 by aschweit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h> 

typedef struct s_arguments	t_arguments;

typedef struct s_philosophers
{
	pthread_t		thread;
	t_arguments		*args;
	int				id;
	long long		last_meal;
	int				time_eaten;
	int				eating;
	int				thinking;
	int				sleeping;
	int				has_finished;
	pthread_mutex_t	meal_mutex;
}	t_philosophers;

typedef struct s_arguments
{
	int				num_phi;
	long long		time_die;
	long long		time_eat;
	long long		time_sleep;
	int				number_eat;
	int				limit_eat;
	int				dead;
	long long		start_time;
	pthread_mutex_t	*fork;
	pthread_mutex_t	dead_mutex;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	finish_mutex;
	pthread_t		monitoring_thread;
	t_philosophers	*philosophers;
}	t_arguments;

int			is_valid_number(const char *str);
int			validate_arguments(int argc, char **argv);
int			check_philosophers_limit(int num_phi);
int			check_time_values(t_arguments *args);
int			check_eat_limit(t_arguments *args, int argc, char **argv);
int			ft_atoi(const char *s);
void		init_philosophers(t_philosophers *philo, t_arguments *arguments);
void		philosophers_creation_threads(t_arguments *arguments);
int			init_arguments(t_arguments *arguments, int argc, char **argv);
void		philosopher_thinking(t_arguments *arguments, int num);
void		death_unlock(t_arguments *arguments, int num, int num2);
void		philosopher_eating(t_arguments *arguments, int num);
void		philosopher_sleeping(t_arguments *arguments, int num);
void		*philosophers_action(void *arg);
int			lock_forks_odd(t_arguments *arguments, int left,
				int right, int id);
int			lock_forks_even(t_arguments *arguments, int left,
				int right, int id);
int			lock_forks(t_arguments *arguments, int left, int right, int id);
void		precise_sleep(long long duration, t_arguments *arguments);
void		finished_eating(t_arguments *arguments, int id);
void		philosophers_update(t_arguments *arguments,
				long long time_now, int num);
void		pthread_single_create(t_arguments *arguments);
void		pthread_multi_create(t_arguments *arguments, int num);
long long	get_time_ms(void);
long long	current_time(t_arguments *arguments);
void		print_status(t_arguments *arguments, int philo_num, char *message);
void		mutex_free(t_arguments *arguments, int num);
void		main_malloc_init(t_arguments *arguments);
int			dead_mutex_lock(t_arguments *arguments);
void		dead_plus(t_arguments *arguments, int i);
int			dead_helper(t_arguments *args, int *all_finished);
void		*dead(void *arg);
void		*single_philo(void *arg);
int			heck_time_values_with_philos(t_arguments *args);
int			check_int_overflow(const char *str);

#endif
