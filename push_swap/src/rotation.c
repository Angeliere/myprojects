/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschweit <aschweit@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:39:00 by aschweit       #+#    #+#             */
/*   Updated: 2025/10/04 18:07:07 by aschweit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* Execute rotations to bring element to top */
void	rotate_to_top(t_stack *stack, int index, char stack_name)
{
	int	cost;
	int	direction;

	cost = calculate_rotation_cost(index, stack->size);
	direction = get_rotation_direction(index, stack->size);
	while (cost > 0)
	{
		if (stack_name == 'a')
		{
			if (direction == 1)
				ra(stack);
			else
				rra(stack);
		}
		else
		{
			if (direction == 1)
				rb(stack);
			else
				rrb(stack);
		}
		cost--;
	}
}

int	get_rotation_direction(int position, int stack_size)
{
	if (position <= stack_size / 2)
		return (1);
	else
		return (-1);
}
