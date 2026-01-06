/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_mutex_lock.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschweit <aschweit@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 12:32:26 by aschweit       #+#    #+#                */
/*   Updated: 2025/12/23 16:52:59 by aschweit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


void eating_mutex_lock(t_arguments *arguments, int num , int num2)
{
	pthread_mutex_lock(&arguments->fork[num]);
	print_status(arguments, num + 1, "grabs left fork\n");
	pthread_mutex_lock(&arguments->fork[num2]);
	print_status(arguments, num + 1, "grabs right fork\n");
	return ;
}

void last_philosophers_eating(t_arguments *arguments, int num, int num2 , int print)
{
	pthread_mutex_lock(&arguments->philosophers[num].meal_mutex);
    arguments->philosophers[num].last_meal = current_time(arguments);
    pthread_mutex_unlock(&arguments->philosophers[num].meal_mutex);
	print_status(arguments, print, "is eating\n");
	precise_sleep(arguments->time_sleep, arguments);
	pthread_mutex_unlock(&arguments->fork[num]);
	pthread_mutex_unlock(&arguments->fork[num2]);
	if (dead_mutex_lock(arguments))
		return ;
	print_status(arguments, print, "finished eating\n");
	return ;
}

void other_philosophers_eating(t_arguments *arguments ,int num , int num2)
{
	pthread_mutex_lock(&arguments->philosophers[num].meal_mutex);
    arguments->philosophers[num].last_meal = current_time(arguments);
    pthread_mutex_unlock(&arguments->philosophers[num].meal_mutex);
	print_status(arguments, num + 1, "is eating\n");
    precise_sleep(arguments->time_sleep, arguments);
	pthread_mutex_unlock(&arguments->fork[num]);
	pthread_mutex_unlock(&arguments->fork[num2]);
	if (dead_mutex_lock(arguments))
		return ;
	print_status(arguments, num + 1, "finished eating\n");
	return ;
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