/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortingbis_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschweit <aschweit@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 16:57:16 by aschweit       #+#    #+#             */
/*   Updated: 2025/10/04 18:04:37 by aschweit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_mins_to_b(t_stack *a, t_stack *b)
{
	int	min_idx;

	while (a->size > 3)
	{
		min_idx = find_min_index(a);
		rotate_to_top(a, min_idx, 'a');
		pb(a, b);
	}
}

int	find_max_in_b(t_stack *b)
{
	int	max_val;
	int	max_idx;
	int	i;

	max_val = b->array[0];
	max_idx = 0;
	i = 1;
	while (i < b->size)
	{
		if (b->array[i] > max_val)
		{
			max_val = b->array[i];
			max_idx = i;
		}
		i++;
	}
	return (max_idx);
}

void	copy_array(int *dest, t_stack *src)
{
	int	i;

	i = 0;
	while (i < src->size)
	{
		dest[i] = src->array[i];
		i++;
	}
}

void	bubble_sort(int *array, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

int	check_overflow(long num)
{
	if (num > 2147483647 || num < -2147483648)
		return (0);
	return (1);
}
