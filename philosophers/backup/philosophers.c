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

long long get_time_ms()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

long long current_time(t_arguments *arguments)
{
    return get_time_ms() - arguments->start_time;
}

int dead_helper(t_arguments *arguments)
{
    pthread_mutex_lock(&arguments->dead_mutex);
    int result = arguments->dead;
    pthread_mutex_unlock(&arguments->dead_mutex);
    return (result);
}

void print_status(t_arguments *arguments, int philo_num, char *message)
{
	if(dead_helper(arguments))
		return;
	pthread_mutex_lock(&arguments->print_mutex);
	if(dead_helper(arguments))
	{
		pthread_mutex_unlock(&arguments->print_mutex);
		return;
	}
	printf("[%lld]philosopher : %d %s",current_time(arguments), philo_num, message);
	pthread_mutex_unlock(&arguments->print_mutex);
}

void *dead(void *arg)
{
	t_arguments *arguments = (t_arguments *)arg;
	long long elasped_time;
	int i;

	while(!dead_helper(arguments))
	{
		i = 0;
		while(i < arguments->num_phi)
		{
			pthread_mutex_lock(&arguments->philosophers[i].meal_mutex);
			elasped_time = current_time(arguments) - arguments->philosophers[i].last_meal;
			pthread_mutex_unlock(&arguments->philosophers[i].meal_mutex);
			if(elasped_time >= arguments->time_die)
			{
				dead_plus(arguments, i);
				return 	(NULL);
			}
			i++;	
		}
		usleep(1000);
	}
	return 	(NULL);
}

void philosopher_thinking(t_arguments *arguments, int num)
{
	if (dead_helper(arguments))
		return ;
	arguments->philosophers[num].thinking = 1;
	print_status(arguments, num + 1, "is thinking\n");
	arguments->philosophers[num].thinking = 0;
	return ;
}

void philosopher_eating(t_arguments *arguments ,int num)
{
	if(num == (arguments->num_phi - 1))
	{
		eating_mutex_lock(arguments, num, 0);
		pthread_mutex_lock(&arguments->fork[num]);
		print_status(arguments, num + 1, "grabs left fork\n");
		pthread_mutex_lock(&arguments->fork[0]);
		print_status(arguments, num + 1, "grabs right fork\n");
		if (dead_helper(arguments))
		{
			death_unlock(arguments, num, 0);
			pthread_mutex_unlock(&arguments->fork[num]);
			pthread_mutex_unlock(&arguments->fork[0]);
			return ;
		}
		print_status(arguments, num + 1, "is eating\n");
		usleep(arguments->time_eat);
	}
	else
	{
		eating_mutex_lock(arguments, num, num + 1);
		pthread_mutex_lock(&arguments->fork[num]);
		print_status(arguments, num + 1, "grabs left fork\n");
		pthread_mutex_lock(&arguments->fork[num + 1]);
		print_status(arguments, num + 1, "grabs right fork\n");
		if (dead_helper(arguments))
		{
			death_unlock(arguments, num , num + 1);
			pthread_mutex_unlock(&arguments->fork[num]);
			pthread_mutex_unlock(&arguments->fork[num + 1]);
			return ;
		}
		print_status(arguments, num + 1, "is eating\n");
		usleep(arguments->time_eat);
	}
	return ;
}

void philosopher_sleeping(t_arguments *arguments, int num)
{	
	arguments->philosophers[num].sleeping = 1;
	if (dead_helper(arguments))
	{
		arguments->philosophers[num].sleeping = 0;
		return ;
	}
	print_status(arguments, num + 1, "is sleeping\n");
	usleep(arguments->time_sleep);
	arguments->philosophers[num].sleeping = 0;
	return ;
}

void	*philosophers_action(void *arg)
{
	t_philosophers *philo = (t_philosophers *)arg;
	t_arguments *arguments;

	arguments = philo->args;
	int id = philo->id - 1;
	while(!dead_helper(arguments))
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
		usleep(500);
	}
	return(0);
}

void philosophers_creation_threads(t_arguments *arguments)
{
	int	num = 0;
	long long time_now = current_time(arguments);
	
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

void mutex_free(t_arguments *arguments, int num)
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
}

int main(int argc, char **argv)
{
	t_arguments	arguments;
	int i = 0;
	
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
	arguments.fork = malloc(sizeof(pthread_mutex_t) * arguments.num_phi);
	if(!arguments.fork)
		return (-1);
	arguments.philosophers = malloc(sizeof(t_philosophers) * (arguments.num_phi));
	if(!arguments.philosophers)
	{	free(arguments.fork);
		return (-1);
	}
	pthread_mutex_init(&arguments.dead_mutex, NULL);
	pthread_mutex_init(&arguments.print_mutex, NULL);
	while(i < arguments.num_phi)
	{
		pthread_mutex_init(&arguments.fork[i], NULL);
		pthread_mutex_init(&arguments.philosophers[i].meal_mutex, NULL);
		arguments.philosophers[i].args = &arguments;
		i++;
	}
	philosophers_creation_threads(&arguments);
	mutex_free(&arguments, arguments.num_phi - 1);
	return (0);
}