/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschweit <aschweit@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 12:32:26 by aschweit       #+#    #+#             	  */
/*   Updated: 2026/01/07 17:21:15 by aschweit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

long long	current_time(t_arguments *arguments)
{
	return (get_time_ms() - arguments->start_time);
}

void	print_status(t_arguments *arguments, int philo_num, char *message)
{
	if (dead_mutex_lock(arguments))
		return ;
	pthread_mutex_lock(&arguments->print_mutex);
	if (dead_mutex_lock(arguments))
	{
		pthread_mutex_unlock(&arguments->print_mutex);
		return ;
	}
	printf("[%lld]philosopher : %d %s",
		current_time(arguments), philo_num, message);
	pthread_mutex_unlock(&arguments->print_mutex);
}

void	mutex_free(t_arguments *arguments, int num)
{
	while (num >= 0)
	{
		pthread_mutex_destroy(&arguments->fork[num]);
		pthread_mutex_destroy(&arguments->philosophers[num].meal_mutex);
		num--;
	}
	free(arguments->fork);
	free(arguments->philosophers);
	pthread_mutex_destroy(&arguments->dead_mutex);
	pthread_mutex_destroy(&arguments->print_mutex);
	pthread_mutex_destroy(&arguments->finish_mutex);
}

void	main_malloc_init(t_arguments *arguments)
{
	int	i;

	i = 0;
	arguments->fork = malloc(sizeof(pthread_mutex_t) * arguments->num_phi);
	if (!arguments->fork)
		return ;
	arguments->philosophers = malloc
		(sizeof(t_philosophers) * (arguments->num_phi));
	if (!arguments->philosophers)
	{
		free(arguments->fork);
		return ;
	}
	pthread_mutex_init(&arguments->dead_mutex, NULL);
	pthread_mutex_init(&arguments->print_mutex, NULL);
	pthread_mutex_init(&arguments->finish_mutex, NULL);
	while (i < arguments->num_phi)
	{
		pthread_mutex_init(&arguments->fork[i], NULL);
		pthread_mutex_init(&arguments->philosophers[i].meal_mutex, NULL);
		init_philosophers(&arguments->philosophers[i], arguments);
		i++;
	}
}
