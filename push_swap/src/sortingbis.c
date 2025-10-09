/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortingbis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschweit <aschweit@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:00:19 by aschweit       #+#    #+#             */
/*   Updated: 2025/10/04 18:03:35 by aschweit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small(t_stack *a, t_stack *b)
{
	int	max_idx;

	push_mins_to_b(a, b);
	sort_three(a);
	while (b->size > 0)
	{
		max_idx = find_max_in_b(b);
		rotate_to_top(b, max_idx, 'b');
		pa(a, b);
	}
}

void	push_to_b_simple(t_stack *a, t_stack *b)
{
	while (a->size > 3)
	{
		pb(a, b);
	}
}

int	*create_sorted_copy(t_stack *a)
{
	int	*sorted;

	sorted = malloc(sizeof(int) * a->size);
	if (!sorted)
		return (NULL);
	copy_array(sorted, a);
	bubble_sort(sorted, a->size);
	return (sorted);
}

int	get_sorted_index(int value, int *sorted, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (sorted[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

void	push_to_b_optimized(t_stack *a, t_stack *b)
{
	t_push_data	data;

	init_push_data(&data, a);
	if (!data.sorted)
	{
		push_to_b_simple(a, b);
		return ;
	}
	push_first_half(a, b, &data);
	push_remaining(a, b, &data);
	free(data.sorted);
}
