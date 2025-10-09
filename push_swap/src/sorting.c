/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschweit <aschweit@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:35:10 by aschweit       #+#    #+#             */
/*   Updated: 2025/10/05 15:24:44 by aschweit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	has_duplicates(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->size)
	{
		j = i + 1;
		while (j < stack->size)
		{
			if (stack->array[i] == stack->array[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->array[i] > stack->array[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	if (a->size < 3)
	{
		if (a->size == 2 && a->array[0] > a->array[1])
			sa(a);
		return ;
	}
	first = a->array[0];
	second = a->array[1];
	third = a->array[2];
	conditional_move(first, second, third, a);
}

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_interger(const char *str, long *out_val)
{
	long	val;

	val = ft_atoi(str);
	*out_val = val;
	if (val < INT_MIN || val > INT_MAX)
		return (0);
	return (1);
}
