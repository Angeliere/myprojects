/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschweit <aschweit@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 12:31:13 by aschweit       #+#    #+#             */
/*   Updated: 2025/10/08 12:32:07 by aschweit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <pthread.h>

typedef struct s_arguments t_arguments;

typedef struct s_philosophers
{
    int         id;
    long long   last_meal;
    int         left_fork;
    int         right_fork;
    int         time_eaten;
    int         eating;
    int        thinking;
    int         sleeping;
    t_arguments *args;
    pthread_t   thread;
    pthread_mutex_t meal_mutex;
}   t_philosophers;

typedef struct s_arguments
{
    int             num_phi;
    int             time_die;
    int             time_eat;
    int             time_sleep;
    int             number_eat;
    int             limit_eat;
    int             dead;
    long long       start_time;
    pthread_t       monitoring_thread;
    pthread_mutex_t *fork;
    t_philosophers   *philosophers;
    pthread_mutex_t dead_mutex;
    pthread_mutex_t print_mutex;
    
}   t_arguments;

long long get_time_ms();
long long current_time(t_arguments *arguments);
int dead_mutex_lock(t_arguments *arguments);
void dead_plus(t_arguments *arguments, int i);
void eating_mutex_lock(t_arguments *arguments, int num , int num2);
void last_philosophers_eating(t_arguments *arguments, int num, int num2, int print);
void other_philosophers_eating(t_arguments *arguments ,int num, int num2);
void death_unlock(t_arguments *arguments, int num , int num2);
void	*philosophers_action(void *arg);
void print_status(t_arguments *arguments, int philo_num, char *message);
void philosophers_creation_threads(t_arguments *arguments);
void main_malloc_init(t_arguments *arguments);
void mutex_free(t_arguments *arguments, int num);
void philosopher_thinking(t_arguments *arguments, int num);
void philosopher_eating(t_arguments *arguments, int num);
void philosopher_sleeping(t_arguments *arguments, int num);
void  *dead(void *arg);
void precise_sleep(long long duration, t_arguments *arguments);

#endif
