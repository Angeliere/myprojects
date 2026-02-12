/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschweit <aschweit@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 12:32:26 by aschweit          #+#    #+#             */
/*   Updated: 2026/02/12 13:59:50 by aschweit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(const char *s)
{
	int			sign;
	long int	r;

	r = 0;
	sign = 1;
	while (*s == 32 || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		r = r * 10 + *s - '0';
		s++;
	}
	return (sign * r);
}

void	init_philosophers(t_philosophers *philo, t_arguments *arguments)
{
	philo->args = arguments;
	philo->id = 0;
	philo->last_meal = 0;
	philo->time_eaten = 0;
	philo->eating = 0;
	philo->thinking = 0;
	philo->sleeping = 0;
	philo->has_finished = 0;
}

void	philosophers_creation_threads(t_arguments *arguments)
{
	int			num;
	long long	time_now;

	num = 0;
	time_now = current_time(arguments);
	philosophers_update(arguments, time_now, num);
	if (arguments->num_phi == 1)
	{
		pthread_single_create(arguments);
		return ;
	}
	pthread_multi_create(arguments, num);
	pthread_create(&arguments->monitoring_thread, NULL, dead, arguments);
	pthread_join(arguments->monitoring_thread, NULL);
	while (arguments->num_phi > num)
	{
		pthread_join(arguments->philosophers[num].thread, NULL);
		num++;
	}
	return ;
}

int	init_arguments(t_arguments *arguments, int argc, char **argv)
{
	arguments->start_time = get_time_ms();
	arguments->num_phi = ft_atoi(argv[1]);
	if (!check_philosophers_limit(arguments->num_phi))
		return (0);
	arguments->time_die = ft_atoi(argv[2]);
	arguments->time_eat = ft_atoi(argv[3]);
	arguments->time_sleep = ft_atoi(argv[4]);
	if (!check_time_values(arguments))
		return (0);
	if (!check_eat_limit(arguments, argc, argv))
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_arguments	arguments;

	if (argc != 5 && argc != 6)
		return (printf("Error: wrong number of arguments\n"));
	if (!validate_arguments(argc, argv))
		return (1);
	arguments = (t_arguments){0};
	if (!init_arguments(&arguments, argc, argv))
		return (1);
	main_malloc_init(&arguments);
	philosophers_creation_threads(&arguments);
	mutex_free(&arguments, arguments.num_phi - 1);
	return (0);
}
