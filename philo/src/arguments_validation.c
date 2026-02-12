/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_validation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschweit <aschweit@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:30:00 by aschweit          #+#    #+#             */
/*   Updated: 2026/02/12 13:59:09 by aschweit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	is_valid_number(const char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	if (!check_int_overflow(str))
		return (0);
	return (1);
}

int	validate_arguments(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_valid_number(argv[i]))
		{
			printf("Error: argument %d is not a valid number\n", i);
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_philosophers_limit(int num_phi)
{
	if (num_phi <= 0)
	{
		printf("Error: number of philosophers must be positive\n");
		return (0);
	}
	if (num_phi > 600)
	{
		printf("Error: too many philosophers (max 600)\n");
		return (0);
	}
	return (1);
}

int	check_time_values(t_arguments *args)
{
	if (args->time_die <= 0)
	{
		printf("Error: time_to_die must be positive\n");
		return (0);
	}
	if (args->time_eat <= 0)
	{
		printf("Error: time_to_eat must be positive\n");
		return (0);
	}
	if (args->time_sleep <= 0)
	{
		printf("Error: time_to_sleep must be positive\n");
		return (0);
	}
	return (1);
}

int	check_eat_limit(t_arguments *args, int argc, char **argv)
{
	if (argc == 6)
	{
		args->number_eat = ft_atoi(argv[5]);
		if (args->number_eat <= 0)
		{
			printf("Error: number_of_times_each_must_eat ");
			printf("must be positive\n");
			return (0);
		}
		args->limit_eat = 1;
	}
	return (1);
}
