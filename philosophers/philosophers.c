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

void philosophers_creation_threads(t_arguments *arguments)
{
	int	num;
	long long time_now;
	
	num = 0;
	time_now = current_time(arguments);
	pthread_create(&arguments->monitoring_thread, NULL , dead, arguments);
	while(num < arguments->num_phi)
	{
		arguments->philosophers[num].id = num + 1;
		arguments->philosophers[num].last_meal = time_now;
		pthread_create(&arguments->philosophers[num].thread, NULL , philosophers_action, &arguments->philosophers[num]);

		num++;
	}
	num = 0;
	pthread_join(arguments->monitoring_thread, NULL);
	while(arguments->num_phi > num)
	{
		pthread_join(arguments->philosophers[num].thread, NULL);
		num++;
	}
}

int main(int argc, char **argv)
{
	t_arguments	arguments;
	int i;
	
	i = 0;
	if(argc != 5 && argc != 6)
	{
		printf("Invalid number of arguments need 5 or 6\n");
		return (-1);
	}
	arguments = (t_arguments){0};
	arguments.start_time = get_time_ms();
	arguments.num_phi = atoi(argv[1]);
	arguments.time_die = atoi(argv[2]) * 1000;
	arguments.time_eat = atoi(argv[3])* 1000;
	arguments.time_sleep = atoi(argv[4])* 1000;
	if(argc == 6)
	{		
		arguments.number_eat = atoi(argv[5]);
		arguments.limit_eat = 1;
	}
	main_malloc_init(&arguments);
	mutex_free(&arguments, arguments.num_phi - 1);
	return (0);
}