/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschweit <aschweit@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 12:32:26 by aschweit       #+#    #+#             */
/*   Updated: 2025/10/08 14:04:26 by aschweit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long current_time(t_arguments *arguments)
{
	struct timeval tv;
	long long timenow;
	gettimeofday(&tv, NULL);
	timenow = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return(timenow - arguments->start_time);
}

int	dead(t_arguments *arguments)
{
	int i;

	i = 0;
	while(i <= arguments->num_phi)
	{
		if(arguments->philosophers[i].last_meal <= arguments->time_die)
		{
			printf("[%lld]philosopher %d died",current_time(arguments), i);
			return(1);
		}
		i++;
	}
	return(0);
}

void mutex_free(t_arguments *arguments, int num)
{
	while (num >= 0)
	{
		pthread_mutex_destroy(&arguments->fork[num]);
		free(&arguments->fork[num]);
		free(&arguments->philosophers[num]);
		num--;
	}
}

void philosopher_thinking(t_arguments *arguments, int num)
{
	printf("[%lld]philosopher : %d sleeping",current_time(arguments), num + 1);
	usleep(arguments->time_think);
}

void philosopher_eating(t_arguments *arguments ,int num)
{
	if(num == (arguments->num_phi + 1))
	{
		
		printf("[%lld]philosopher : %d \n grabs fork number: %d\n",current_time(arguments), num  , num );
		pthread_mutex_lock(&arguments->fork[num - 1]);
		printf("[%lld]philosopher : %d \n grabs fork number: %d\n",current_time(arguments),num , 1);
		pthread_mutex_lock(&arguments->fork[0]);
		usleep(arguments->time_eat);
		pthread_mutex_unlock(&arguments->fork[num - 1]);
		pthread_mutex_unlock(&arguments->fork[0]);
		printf("[%lld]philosopher : %d finished eating",current_time(arguments), num);
	}
	else
	{
		printf("[%lld]philosopher : %d \n grabs fork number: %d\n",current_time(arguments), num  , num );
		pthread_mutex_lock(&arguments->fork[num - 1]);
		printf("[%lld]philosopher : %d \n grabs fork number: %d\n",current_time(arguments),num ,  num + 1);
		pthread_mutex_lock(&arguments->fork[num]);
		usleep(arguments->time_eat);
		pthread_mutex_unlock(&arguments->fork[num - 1]);
		pthread_mutex_unlock(&arguments->fork[num]);
		printf("[%lld]philosopher : %d finished eating",current_time(arguments),  num);
	}
}

void philosopher_sleeping(t_arguments *arguments, int num)
{	
	printf("[%lld]philosopher : %d sleeping",current_time(arguments), num + 1);
	usleep(arguments->time_sleep);
}

void	*philosophers_action(void *arg)
{
	t_arguments arguments;

	int id;

	id = *(int*)arg;
	while (!dead(&arguments))
	{
		if(arguments.philosophers[id].time_eaten == 0)
			return (NULL);
		philosopher_eating(&arguments, id);
		philosopher_sleeping(&arguments, id);
		philosopher_thinking(&arguments, id);
		usleep(500);
	}
	return(0);
}

void philosophers_creation_threads(t_arguments *arguments)
{
	int	num = 0;
	while(arguments->num_phi >= num)
	{
		arguments->philosophers[num].id = num + 1;
		pthread_create(arguments->philosophers[num].thread, NULL , philosophers_action, &arguments->philosophers[num].id);
		num++;
	}
	num = 0;
	while(arguments->num_phi >= num)
	{
		pthread_join(*arguments->philosophers[num].thread, NULL);
		num++;
	}
}

int main(int argc, char **argv)
{
	t_arguments	arguments;
	int num;
	
	arguments = (t_arguments){0};
	arguments.start_time = current_time(&arguments);
	if (argc == 5)
	{
		num = atoi(argv[1]);
		arguments.num_phi = atoi(argv[1]);
		arguments.time_die = atoi(argv[2]);
		arguments.time_eat = atoi(argv[3]);
		arguments.time_sleep = atoi(argv[4]);
		arguments.fork = malloc(sizeof(pthread_mutex_t) * arguments.num_phi);
		if(!arguments.fork)
			return (-1);
		arguments.philosophers = malloc(sizeof(pthread_t) * (arguments.num_phi));
		if(!arguments.philosophers)
			return (-1);
		philosophers_creation_threads(&arguments);
		while(num > 0)
		{
			pthread_mutex_init(&arguments.fork[num], NULL);
			num--;
		}
	}
	else if(argc == 6)
	{		
		num = atoi(argv[1]);
		arguments.num_phi = atoi(argv[1]);
		arguments.time_die = atoi(argv[2]);
		arguments.time_eat = atoi(argv[3]);
		arguments.time_sleep = atoi(argv[4]);
		arguments.number_eat = atoi(argv[5]);
		printf("[%lld]philosopher : %d finished eating \n",current_time(&arguments) ,arguments.num_phi);
		arguments.fork = malloc(sizeof(pthread_mutex_t) * arguments.num_phi);
		if(!arguments.fork)
			return (-1);
		printf("[%lld]philosopher : %d finished eating \n",current_time(&arguments) ,arguments.time_sleep);
		arguments.philosophers = malloc(sizeof(pthread_t) * (arguments.num_phi));
		if(!arguments.philosophers)
			return (-1);
		/*philosophers_creation_threads(&arguments);
		while(num > 0)
		{
			pthread_mutex_init(&arguments.fork[num], NULL);
			num--;
		}*/
	}
	else
		printf("Invalid number of arguments need 5");
	/*mutex_free(&arguments, arguments.num_phi - 1);*/
	
	return (0);
}