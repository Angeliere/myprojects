/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_mutex_lock.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschweit <aschweit@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 12:32:26 by aschweit       #+#    #+#                */
/*   Updated: 2025/12/23 17:48:09 by aschweit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void lock_forks_odd(t_arguments *arguments, int left, int right, int id)
{
    pthread_mutex_lock(&arguments->fork[left]);
    if (dead_mutex_lock(arguments))
    {
        pthread_mutex_unlock(&arguments->fork[left]);
        return;
    }
    print_status(arguments, id + 1, "grabs left fork\n");
    pthread_mutex_lock(&arguments->fork[right]);
    if (dead_mutex_lock(arguments))
    {
        pthread_mutex_unlock(&arguments->fork[right]);
        pthread_mutex_unlock(&arguments->fork[left]);
        return;
    }
    print_status(arguments, id + 1, "grabs right fork\n");
}

void lock_forks_even(t_arguments *arguments, int left, int right, int id)
{
    pthread_mutex_lock(&arguments->fork[right]);
    if (dead_mutex_lock(arguments))
    {
        pthread_mutex_unlock(&arguments->fork[right]);
        return;
    }
    print_status(arguments, id + 1, "grabs right fork\n");
    pthread_mutex_lock(&arguments->fork[left]);
    if (dead_mutex_lock(arguments))
    {
        pthread_mutex_unlock(&arguments->fork[left]);
        pthread_mutex_unlock(&arguments->fork[right]);
        return;
    }
    print_status(arguments, id + 1, "grabs left fork\n");
}

void lock_forks(t_arguments *arguments, int left, int right, int id)
{
    if (id % 2 == 0)
    {
        lock_forks_even(arguments, left, right, id);
    }
    else
    {
        lock_forks_odd(arguments, left, right, id);
    }
}

void precise_sleep(long long duration, t_arguments *arguments)
{
    long long start;

    start = current_time(arguments);
    while (!dead_mutex_lock(arguments))
    {
        if (current_time(arguments) - start >= duration)
            break;
        usleep(50);
    }
}

void finished_eating(t_arguments *arguments, int id)
{
    t_philosophers *philo;
    
    philo = &arguments->philosophers[id];
    pthread_mutex_lock(&arguments->finish_mutex);
    philo->has_finished = 1;
    pthread_mutex_unlock(&arguments->finish_mutex);
	print_status(arguments, id + 1, "finished eating\n");
	return;
}