/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschweit <aschweit@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:12:46 by aschweit       #+#    #+#             */
/*   Updated: 2025/10/04 18:22:08 by aschweit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(int capacity)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->array = (int *)malloc(sizeof(int) * capacity);
	if (!stack->array)
	{
		free(stack);
		return (NULL);
	}
	stack->size = 0;
	stack->capacity = capacity;
	return (stack);
}

int	count_words(char *str)
{
	int	count;
	int	in_word;
	int	i;

	count = 0;
	in_word = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		{
			if (!in_word)
			{
				count++;
				in_word = 1;
			}
		}
		else
			in_word = 0;
		i++;
	}
	return (count);
}

void	free_stacks(t_stack *a, t_stack *b)
{
	if (a)
	{
		if (a->array)
			free(a->array);
		free(a);
	}
	if (b)
	{
		if (b->array)
			free(b->array);
		free(b);
	}
}

void	align_stack(t_stack *a)
{
	int	min_idx;
	int	cost;

	min_idx = find_min_index(a);
	cost = calculate_rotation_cost(min_idx, a->size);
	if (min_idx <= a->size / 2)
	{
		while (min_idx > 0)
		{
			ra(a);
			min_idx--;
		}
	}
	else
	{
		while (min_idx != 0)
		{
			rra(a);
			min_idx++;
			if (min_idx >= a->size)
				min_idx = 0;
		}
	}
}

int	calculate_rotation_cost(int position, int stack_size)
{
	if (position <= stack_size / 2)
		return (position);
	else
		return (stack_size - position);
}
