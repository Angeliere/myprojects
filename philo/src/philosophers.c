/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschweit <aschweit@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 12:32:26 by aschweit       #+#    #+#             	  */
/*   Updated: 2025/12/23 17:31:10 by aschweit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void philosophers_creation_threads(t_arguments *arguments)
{
	int	num;
	long long time_now;
	
	num = 0;
	time_now = current_time(arguments);
	philosophers_update(arguments, time_now, num);
	if (arguments->num_phi == 1)
	{
    	pthread_single_create(arguments);
    	return;
	}
	pthread_multi_create(arguments, num);
	pthread_create(&arguments->monitoring_thread, NULL , dead, arguments);
	pthread_join(arguments->monitoring_thread, NULL);
	while(arguments->num_phi > num)
	{
		pthread_join(arguments->philosophers[num].thread, NULL);
		num++;
	}
	return;
}

int main(int argc, char **argv)
{
	t_arguments	arguments;

	if(argc != 5 && argc != 6)
	{
		printf("Invalid number of arguments need 5 or 6\n");
		return (-1);
	}
	arguments = (t_arguments){0};
	arguments.start_time = get_time_ms();
	arguments.num_phi = atoi(argv[1]);
	arguments.time_die = atoi(argv[2]);
	arguments.time_eat = atoi(argv[3]);
	arguments.time_sleep = atoi(argv[4]);
	if(argc == 6)
	{		
		arguments.number_eat = atoi(argv[5]);
		arguments.limit_eat = 1;
	}
	main_malloc_init(&arguments);
	philosophers_creation_threads(&arguments);
	mutex_free(&arguments, arguments.num_phi - 1);
	return (0);
}
