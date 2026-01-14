/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_creation_util.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschweit <aschweit@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 12:32:26 by aschweit       #+#    #+#             	  */
/*   Updated: 2026/01/07 17:16:47 by aschweit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philosophers_update(t_arguments *arguments, long long time_now, int num)
{
	while (num < arguments->num_phi)
	{
		arguments->philosophers[num].id = num + 1;
		arguments->philosophers[num].last_meal = time_now;
		num++;
	}
}

void	pthread_single_create(t_arguments *arguments)
{
	pthread_create(&arguments->philosophers[0].thread, NULL,
		single_philo, &arguments->philosophers[0]);
	pthread_create(&arguments->monitoring_thread, NULL, dead, arguments);
	pthread_join(arguments->monitoring_thread, NULL);
	pthread_join(arguments->philosophers[0].thread, NULL);
	return ;
}

void	pthread_multi_create(t_arguments *arguments, int num)
{
	while (num < arguments->num_phi)
	{
		pthread_create(&arguments->philosophers[num].thread,
			NULL, philosophers_action, &arguments->philosophers[num]);
		num++;
	}
	return ;
}
