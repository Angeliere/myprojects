/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_actions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschweit <aschweit@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 12:32:26 by aschweit       #+#    #+#             	  */
/*   Updated: 2025/12/23 17:21:14 by aschweit         ###   ########.fr       */
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
	if(num == (arguments->num_phi - 1))
	{
		eating_mutex_lock(arguments, 0, num);
		if (dead_mutex_lock(arguments))
		{
			death_unlock(arguments, 0, num);
			return ;
		}
		last_philosophers_eating(arguments, num, 0, num + 1);
	}
	else
	{
		eating_mutex_lock(arguments, num, num + 1);
		if (dead_mutex_lock(arguments))
		{
			death_unlock(arguments, num , num + 1);
			return ;
		}
		other_philosophers_eating(arguments, num, num + 1);
	}
	return ;
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
	precise_sleep(arguments->time_sleep, arguments);
	arguments->philosophers[num].sleeping = 0;
	return ;
}

void	*philosophers_action(void *arg)
{
	t_philosophers *philo;
	t_arguments *arguments;

	philo = (t_philosophers *)arg;
	arguments = philo->args;
	int id = philo->id - 1; 
	while(!dead_mutex_lock(arguments))
	{
		philosopher_thinking(arguments, id);
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
	}
	return(0);
}
