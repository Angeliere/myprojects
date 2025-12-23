/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschweit <aschweit@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 12:32:26 by aschweit       #+#    #+#             	  */
/*   Updated: 2025/10/08 14:04:26 by aschweit         ###   ########.fr       */
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
    return (NULL) ;
}

void *dead(void *arg)
{
	t_arguments *arguments;
	long long elasped_time;
	int i;

	arguments = (t_arguments *)arg;
	while(!dead_mutex_lock(arguments))
	{
		i = 0;
		while(i < arguments->num_phi)
		{
			pthread_mutex_lock(&arguments->philosophers[i].meal_mutex);
			elasped_time = current_time(arguments) - arguments->philosophers[i].last_meal;
			pthread_mutex_unlock(&arguments->philosophers[i].meal_mutex);
			if(elasped_time >= arguments->time_die)
			{
				dead_plus(arguments, i);
				return 	(NULL);
			}
			i++;	
		}
		usleep(1000);
	}
	return 	(NULL);
}