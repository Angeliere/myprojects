/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_find.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschweit <aschweit@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:43:40 by aschweit       #+#    #+#             */
/*   Updated: 2025/10/05 15:24:10 by aschweit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	find_min_index(t_stack *stack)
{
	int	i;
	int	min_idx;
	int	min_val;

	if (stack->size == 0)
		return (-1);
	min_idx = 0;
	min_val = stack->array[0];
	i = 1;
	while (i < stack->size)
	{
		if (stack->array[i] < min_val)
		{
			min_val = stack->array[i];
			min_idx = i;
		}
		i++;
	}
	return (min_idx);
}

int	find_max_index(t_stack *stack)
{
	int	i;
	int	max_idx;
	int	max_val;

	if (stack->size == 0)
		return (-1);
	max_idx = 0;
	max_val = stack->array[0];
	i = 1;
	while (i < stack->size)
	{
		if (stack->array[i] > max_val)
		{
			max_val = stack->array[i];
			max_idx = i;
		}
		i++;
	}
	return (max_idx);
}

int	find_target_position(int value, t_stack *stack)
{
	int	i;
	int	target_pos;
	int	target_val;

	if (stack->size == 0)
		return (0);
	target_val = 2147483647;
	target_pos = -1;
	i = 0;
	while (i < stack->size)
	{
		if (stack->array[i] > value && stack->array[i] < target_val)
		{
			target_val = stack->array[i];
			target_pos = i;
		}
		i++;
	}
	if (target_pos == -1)
		target_pos = find_min_index(stack);
	return (target_pos);
}

t_move	find_cheapest_move(t_stack *a, t_stack *b)
{
	t_move	best;
	t_move	current;
	int		i;

	if (b->size == 0)
	{
		best.cost = 0;
		best.index_b = 0;
		best.target_a = 0;
		return (best);
	}
	best = calculate_move_cost(0, a, b);
	i = 1;
	while (i < b->size)
	{
		current = calculate_move_cost(i, a, b);
		if (current.cost < best.cost)
			best = current;
		i++;
	}
	return (best);
}

t_move	calculate_move_cost(int idx_b, t_stack *a, t_stack *b)
{
	t_move	move;
	int		cost_a;
	int		cost_b;
	int		dir_a;
	int		dir_b;

	move.index_b = idx_b;
	move.target_a = find_target_position(b->array[idx_b], a);
	cost_a = calculate_rotation_cost(move.target_a, a->size);
	cost_b = calculate_rotation_cost(idx_b, b->size);
	dir_a = get_rotation_direction(move.target_a, a->size);
	dir_b = get_rotation_direction(idx_b, b->size);
	if (dir_a == dir_b)
	{
		if (cost_a > cost_b)
			move.cost = cost_a;
		else
			move.cost = cost_b;
	}
	else
		move.cost = cost_a + cost_b;
	return (move);
}
