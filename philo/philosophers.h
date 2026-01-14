/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschweit <aschweit@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 12:31:13 by aschweit       #+#    #+#             */
/*   Updated: 2026/01/07 16:30:18 by aschweit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <pthread.h>

typedef struct s_arguments	t_arguments;

typedef struct s_philosophers
{
	int				id;
	int				time_eaten;
	int				eating;
	int				thinking;
	int				sleeping;
	int				has_finished;
	long long		last_meal;
	t_arguments		*args;
	pthread_t		thread;
	pthread_mutex_t	meal_mutex;

}	t_philosophers;

typedef struct s_arguments
{
	int					num_phi;
	int					time_die;
	int					time_eat;
	int					time_sleep;
	int					number_eat;
	int					limit_eat;
	int					dead;
	long long			start_time;
	pthread_t			monitoring_thread;
	t_philosophers		*philosophers;
	pthread_mutex_t		*fork;
	pthread_mutex_t		dead_mutex;
	pthread_mutex_t		print_mutex;
	pthread_mutex_t		finish_mutex;

}	t_arguments;

long long	get_time_ms(void);
long long	current_time(t_arguments *arguments);
int			dead_mutex_lock(t_arguments *arguments);
int			lock_forks(t_arguments *arguments, int left, int right, int id);
void		dead_plus(t_arguments *arguments, int i);
void		eating_mutex_lock(t_arguments *arguments, int num, int num2);
void		last_philosophers_eating(t_arguments *arguments,
				int num, int num2, int print);
void		other_philosophers_eating(t_arguments *arguments,
				int num, int num2);
void		death_unlock(t_arguments *arguments, int num, int num2);
void		*philosophers_action(void *arg);
void		print_status(t_arguments *arguments, int philo_num, char *message);
void		philosophers_creation_threads(t_arguments *arguments);
void		main_malloc_init(t_arguments *arguments);
void		mutex_free(t_arguments *arguments, int num);
void		philosopher_thinking(t_arguments *arguments, int num);
void		philosopher_eating(t_arguments *arguments, int num);
void		philosopher_sleeping(t_arguments *arguments, int num);
void		*dead(void *arg);
void		precise_sleep(long long duration, t_arguments *arguments);
void		*single_philo(void *arg);
void		pthread_single_create(t_arguments *arguments);
void		pthread_multi_create(t_arguments *arguments, int num);
void		philosophers_update(t_arguments *arguments,
				long long time_now, int num);
void		finished_eating(t_arguments *arguments, int id);
void		init_philosophers(t_philosophers *philo, t_arguments *arguments);

#endif
