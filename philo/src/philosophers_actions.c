/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_actions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschweit <aschweit@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 12:32:26 by aschweit       #+#    #+#             	  */
/*   Updated: 2025/12/23 17:50:23 by aschweit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

void philosopher_thinking(t_arguments *arguments, int num)
{
	if (dead_mutex_lock(arguments))
		return ;
	arguments->philosophers[num].thinking = 1;
	print_status(arguments, num + 1, "is thinking\n");
	arguments->philosophers[num].thinking = 0;
	return ;
}

void death_unlock(t_arguments *arguments, int num , int num2)
{
	pthread_mutex_unlock(&arguments->fork[num]);
	pthread_mutex_unlock(&arguments->fork[num2]);
	return ;
}

void philosopher_eating(t_arguments *arguments ,int num)
{
	int left;
    int right;

    left = num;
    right = (num + 1) % arguments->num_phi;

    lock_forks(arguments, left, right, num);

    if (dead_mutex_lock(arguments))
    {
        pthread_mutex_unlock(&arguments->fork[left]);
        pthread_mutex_unlock(&arguments->fork[right]);
        return;
    }

    pthread_mutex_lock(&arguments->philosophers[num].meal_mutex);
    arguments->philosophers[num].last_meal = current_time(arguments);
    pthread_mutex_unlock(&arguments->philosophers[num].meal_mutex);

    print_status(arguments, num + 1, "is eating\n");
    precise_sleep(arguments->time_eat, arguments);

    pthread_mutex_unlock(&arguments->fork[left]);
    pthread_mutex_unlock(&arguments->fork[right]);

    if (!dead_mutex_lock(arguments))
        print_status(arguments, num + 1, "finished eating\n");
}

void philosopher_sleeping(t_arguments *arguments, int num)
{	
	arguments->philosophers[num].sleeping = 1;
	if (dead_mutex_lock(arguments))
	{
		arguments->philosophers[num].sleeping = 0;
		return ;
	}
	print_status(arguments, num + 1, "is sleeping\n");
	precise_sleep(arguments->time_eat, arguments);
	arguments->philosophers[num].sleeping = 0;
	return ;
}

void	*philosophers_action(void *arg)
{
	t_philosophers *philo;
	t_arguments *arguments;
	int id;

	philo = (t_philosophers *)arg;
	arguments = philo->args;
	id = philo->id - 1;
	if (id % 2 == 0)
        precise_sleep(arguments->time_eat / 2, arguments); 
	while(!dead_mutex_lock(arguments))
	{
		philosopher_eating(arguments, id);
		if(arguments->limit_eat)
		{
			arguments->philosophers[id].time_eaten++;
			if(arguments->philosophers[id].time_eaten == arguments->number_eat)
			{
				print_status(arguments, id + 1, "finished eating\n");
				return (NULL);
			}
		}
		philosopher_sleeping(arguments, id);
		print_status(arguments, id + 1, "is thinking\n");
	}
	return(NULL);
}
