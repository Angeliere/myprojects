/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead_monitoring.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschweit <aschweit@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 12:32:26 by aschweit       #+#    #+#             	  */
/*   Updated: 2026/01/07 17:04:17 by aschweit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

int	dead_mutex_lock(t_arguments *arguments)
{
	int	result;

	pthread_mutex_lock(&arguments->dead_mutex);
	result = arguments->dead;
	pthread_mutex_unlock(&arguments->dead_mutex);
	return (result);
}

void	dead_plus(t_arguments *arguments, int i)
{
	print_status(arguments, i + 1, "died\n");
	pthread_mutex_lock(&arguments->dead_mutex);
	arguments->dead = 1;
	pthread_mutex_unlock(&arguments->dead_mutex);
	return ;
}

int	dead_helper(t_arguments *args, int *all_finished)
{
	int			i;
	int			finished;
	long long	elapsed;

	i = -1;
	while (++i < args->num_phi)
	{
		pthread_mutex_lock(&args->finish_mutex);
		finished = args->philosophers[i].has_finished;
		pthread_mutex_unlock(&args->finish_mutex);
		if (finished)
			continue ;
		*all_finished = 0;
		pthread_mutex_lock(&args->philosophers[i].meal_mutex);
		elapsed = current_time(args) - args
			->philosophers[i].last_meal;
		pthread_mutex_unlock(&args->philosophers[i].meal_mutex);
		if (elapsed > args->time_die)
		{
			dead_plus(args, i);
			return (1);
		}
	}
	return (0);
}

void	*dead(void *arg)
{
	t_arguments	*args;
	int			all_finished;

	args = (t_arguments *)arg;
	while (!dead_mutex_lock(args))
	{
		all_finished = 1;
		if (dead_helper(args, &all_finished))
			return (NULL);
		if (all_finished)
			return (NULL);
		usleep(500);
	}
	return (NULL);
}

void	*single_philo(void *arg)
{
	t_philosophers	*philo;
	t_arguments		*arguments;

	philo = (t_philosophers *)arg;
	arguments = philo->args;
	pthread_mutex_lock(&arguments->fork[philo->id - 1]);
	print_status(arguments, 1, "has taken a fork\n");
	while (!dead_mutex_lock(philo->args))
	{
		usleep(1000);
	}
	pthread_mutex_unlock(&arguments->fork[philo->id - 1]);
	return (NULL);
}
