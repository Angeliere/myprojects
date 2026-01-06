/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead_monitoring.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschweit <aschweit@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 12:32:26 by aschweit       #+#    #+#             	  */
/*   Updated: 2025/12/23 17:43:15 by aschweit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

int dead_mutex_lock(t_arguments *arguments)
{
    pthread_mutex_lock(&arguments->dead_mutex);
    int result = arguments->dead;
    pthread_mutex_unlock(&arguments->dead_mutex);
    return (result);
}

void dead_plus(t_arguments *arguments, int i)
{
    print_status(arguments, i + 1, "died\n");
	pthread_mutex_lock(&arguments->dead_mutex);
	arguments->dead = 1;
	pthread_mutex_unlock(&arguments->dead_mutex);
    return;
}

void *dead(void *arg)
{
	t_arguments *arguments;
	long long elasped_time;
	int i;
	int finished;

	arguments = (t_arguments *)arg;
	while(!dead_mutex_lock(arguments))
	{
		i = 0;
		int all_finished = 1;
		while(i < arguments->num_phi)
		{
			pthread_mutex_lock(&arguments->finish_mutex);
        	finished = arguments->philosophers[i].has_finished;
            pthread_mutex_unlock(&arguments->finish_mutex);
			if (finished)
            {
                i++;
                continue;
            }
			all_finished = 0;
			pthread_mutex_lock(&arguments->philosophers[i].meal_mutex);
			elasped_time = current_time(arguments) - arguments->philosophers[i].last_meal;
			pthread_mutex_unlock(&arguments->philosophers[i].meal_mutex);
			if(elasped_time > arguments->time_die)
			{
				dead_plus(arguments, i);
				return (NULL) ;
			}
			i++;	
		}
		if (all_finished)
            return NULL;
		usleep(1000);
	}
	return (NULL);
}

void *single_philo(void *arg)
{
    t_philosophers *philo;
	t_arguments *arguments;
    
	philo = (t_philosophers *)arg;
	arguments = philo->args;
    pthread_mutex_lock(&arguments->fork[philo->id - 1]);
    print_status(arguments, 1 , "has taken a fork\n");
    
    while (!dead_mutex_lock(philo->args))
    {
        usleep(1000);
    }
    
    pthread_mutex_unlock(&arguments->fork[philo->id - 1]);
    return (NULL);
}