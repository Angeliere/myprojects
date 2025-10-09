/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschweit <aschweit@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 16:10:07 by aschweit       #+#    #+#             */
/*   Updated: 2025/10/04 18:26:17 by aschweit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_number(char *str, int *value)
{
	long	result;
	int		sign;
	int		i;

	i = 0;
	sign = get_sign(str, &i);
	if (!convert_to_number(str, i, &result))
		return (0);
	if (result * sign > 2147483647 || result * sign < -2147483648)
		return (0);
	*value = (int)(result * sign);
	return (1);
}

int	process_single_argument(char *arg, t_stack *a)
{
	int	value;

	if (!parse_number(arg, &value))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (a->size >= a->capacity)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	a->array[a->size] = value;
	a->size++;
	return (1);
}

int	parse_multiple_args(int argc, char **argv, t_stack *a)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!process_single_argument(argv[i], a))
			return (0);
		i++;
	}
	return (1);
}

int	parse_single_arg(char *str, t_stack *a)
{
	int		i;
	int		j;
	char	temp[12];

	i = 0;
	while (str[i])
	{
		if (!skip_whitespace(str, &i))
			break ;
		j = 0;
		if (!extract_sign(str, &i, temp, &j))
			return (0);
		extract_digits(str, &i, temp, &j);
		if (!add_to_stack(a, temp))
			return (0);
	}
	if (a->size == 0)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}

int	parse_arguments(int argc, char **argv, t_stack *a)
{
	if (argc == 2)
	{
		if (!parse_single_arg(argv[1], a))
			return (0);
	}
	else
	{
		if (!parse_multiple_args(argc, argv, a))
			return (0);
	}
	if (has_duplicates(a))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}
