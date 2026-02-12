/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_mutex_lock.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschweit <aschweit@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 12:32:26 by aschweit       #+#    #+#                */
/*   Updated: 2026/01/09 17:08:25 by aschweit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	lock_forks_odd(t_arguments *arguments, int left, int right, int id)
{
	pthread_mutex_lock(&arguments->fork[left]);
	if (dead_mutex_lock(arguments))
	{
		pthread_mutex_unlock(&arguments->fork[left]);
		return (0);
	}
	print_status(arguments, id + 1, "has taken a fork\n");
	pthread_mutex_lock(&arguments->fork[right]);
	if (dead_mutex_lock(arguments))
	{
		pthread_mutex_unlock(&arguments->fork[right]);
		pthread_mutex_unlock(&arguments->fork[left]);
		return (0);
	}
	print_status(arguments, id + 1, "has taken a fork\n");
	return (1);
}

int	lock_forks_even(t_arguments *arguments, int left, int right, int id)
{
	pthread_mutex_lock(&arguments->fork[right]);
	if (dead_mutex_lock(arguments))
	{
		pthread_mutex_unlock(&arguments->fork[right]);
		return (0);
	}
	print_status(arguments, id + 1, "has taken a fork\n");
	pthread_mutex_lock(&arguments->fork[left]);
	if (dead_mutex_lock(arguments))
	{
		pthread_mutex_unlock(&arguments->fork[left]);
		pthread_mutex_unlock(&arguments->fork[right]);
		return (0);
	}
	print_status(arguments, id + 1, "has taken a fork\n");
	return (1);
}

int	lock_forks(t_arguments *arguments, int left, int right, int id)
{
	if (id % 2 == 0)
		return (lock_forks_even(arguments, left, right, id));
	else
		return (lock_forks_odd(arguments, left, right, id));
}

void	precise_sleep(long long duration, t_arguments *arguments)
{
	long long	start;
	long long	elapsed;

	start = current_time(arguments);
	while (!dead_mutex_lock(arguments))
	{
		elapsed = current_time(arguments) - start;
		if (elapsed >= duration)
			break ;
		if (duration - elapsed > 1)
			usleep(500);
		else
			usleep(50);
	}
}

void	finished_eating(t_arguments *arguments, int id)
{
	t_philosophers	*philo;

	philo = &arguments->philosophers[id];
	pthread_mutex_lock(&arguments->finish_mutex);
	philo->has_finished = 1;
	pthread_mutex_unlock(&arguments->finish_mutex);
	print_status(arguments, id + 1, "finished eating\n");
	return ;
}
