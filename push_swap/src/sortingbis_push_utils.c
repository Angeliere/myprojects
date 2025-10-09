/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortingbis_push_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschweit <aschweit@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 17:36:50 by aschweit       #+#    #+#             */
/*   Updated: 2025/10/04 17:37:08 by aschweit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_push_data(t_push_data *data, t_stack *a)
{
	data->original_size = a->size;
	data->sorted = create_sorted_copy(a);
	data->pushed_count = 0;
	data->threshold = data->original_size / 2;
}

void	push_first_half(t_stack *a, t_stack *b, t_push_data *data)
{
	int	i;
	int	sorted_idx;

	i = 0;
	while (i < a->size * 2 && data->pushed_count < data->threshold
		&& a->size > 3)
	{
		sorted_idx = get_sorted_index(a->array[0], data->sorted,
				data->original_size);
		if (sorted_idx < data->threshold)
		{
			pb(a, b);
			data->pushed_count++;
			if (b->size > 1 && sorted_idx < data->threshold / 2)
				rb(b);
			i = 0;
		}
		else
		{
			ra(a);
			i++;
		}
	}
}

void	push_remaining(t_stack *a, t_stack *b, t_push_data *data)
{
	int	sorted_idx;

	while (a->size > 3)
	{
		pb(a, b);
		if (b->size > 1)
		{
			sorted_idx = get_sorted_index(b->array[0], data->sorted,
					data->original_size);
			if (sorted_idx < data->original_size * 3 / 4)
				rb(b);
		}
	}
}
