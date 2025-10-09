/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschweit <aschweit@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 16:13:07 by aschweit       #+#    #+#             */
/*   Updated: 2025/10/04 18:01:53 by aschweit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	finish_rotation_a(t_stack *a, int cost_a, int dir_a)
{
	while (cost_a > 0)
	{
		if (dir_a == 1)
			ra(a);
		else
			rra(a);
		cost_a--;
	}
}

static void	finish_rotation_b(t_stack *b, int cost_b, int dir_b)
{
	while (cost_b > 0)
	{
		if (dir_b == 1)
			rb(b);
		else
			rrb(b);
		cost_b--;
	}
}

void	execute_move(t_move move, t_stack *a, t_stack *b)
{
	int	dir_a;
	int	dir_b;
	int	cost_a;
	int	cost_b;

	dir_a = get_rotation_direction(move.target_a, a->size);
	dir_b = get_rotation_direction(move.index_b, b->size);
	cost_a = calculate_rotation_cost(move.target_a, a->size);
	cost_b = calculate_rotation_cost(move.index_b, b->size);
	while (cost_a > 0 && cost_b > 0 && dir_a == dir_b)
	{
		if (dir_a == 1)
			rr(a, b);
		else
			rrr(a, b);
		cost_a--;
		cost_b--;
	}
	finish_rotation_a(a, cost_a, dir_a);
	finish_rotation_b(b, cost_b, dir_b);
	pa(a, b);
}
