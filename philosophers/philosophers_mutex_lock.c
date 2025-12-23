/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschweit <aschweit@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 12:32:26 by aschweit       #+#    #+#                */
/*   Updated: 2025/10/08 14:04:26 by aschweit         ###   ########.fr       */
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

void last_philosophers_eating(t_arguments *arguments, int num)
{
	pthread_mutex_lock(&arguments->philosophers[num].meal_mutex);
	arguments->philosophers[num].last_meal = current_time(arguments);
	pthread_mutex_unlock(&arguments->philosophers[num].meal_mutex);
	pthread_mutex_unlock(&arguments->fork[num]);
	pthread_mutex_unlock(&arguments->fork[0]);
	if (dead_helper(arguments))
		return ;
	print_status(arguments, num + 1, "finished eating\n");
	return ;
}

void other_philosophers_eating(t_arguments *arguments ,int num)
{
	pthread_mutex_lock(&arguments->philosophers[num].meal_mutex);
	arguments->philosophers[num].last_meal = current_time(arguments);
	pthread_mutex_unlock(&arguments->philosophers[num].meal_mutex);
	pthread_mutex_unlock(&arguments->fork[num]);
	pthread_mutex_unlock(&arguments->fork[num + 1]);
	if (dead_helper(arguments))
		return ;
	print_status(arguments, num + 1, "finished eating\n");
	return ;
}