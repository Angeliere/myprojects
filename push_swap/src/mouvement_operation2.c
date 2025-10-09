/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement_operation2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschweit <aschweit@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:21:16 by aschweit       #+#    #+#             */
/*   Updated: 2025/10/04 18:28:39 by aschweit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	rb(t_stack *b)
{
	int	temp;
	int	i;

	if (b->size < 2)
		return ;
	temp = b->array[0];
	i = 0;
	while (i < b->size - 1)
	{
		b->array[i] = b->array[i + 1];
		i++;
	}
	b->array[b->size - 1] = temp;
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	int	temp;

	if (a->size >= 2)
	{
		temp = a->array[0];
		array_swap_inc(a->array, a->size);
		a->array[a->size - 1] = temp;
	}
	if (b->size >= 2)
	{
		temp = b->array[0];
		array_swap_inc(b->array, b->size);
		b->array[b->size - 1] = temp;
	}
	write(1, "rr\n", 3);
}

void	rra(t_stack *a)
{
	int	temp;
	int	i;

	if (a->size < 2)
		return ;
	temp = a->array[a->size - 1];
	i = a->size - 1;
	while (i > 0)
	{
		a->array[i] = a->array[i - 1];
		i--;
	}
	a->array[0] = temp;
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	int	temp;
	int	i;

	if (b->size < 2)
		return ;
	temp = b->array[b->size - 1];
	i = b->size - 1;
	while (i > 0)
	{
		b->array[i] = b->array[i - 1];
		i--;
	}
	b->array[0] = temp;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	int	temp;
	int	i;

	if (a->size >= 2)
	{
		temp = a->array[a->size - 1];
		i = a->size - 1;
		array_swap_dec(a->array, i);
		a->array[0] = temp;
	}
	if (b->size >= 2)
	{
		temp = b->array[b->size - 1];
		i = b->size - 1;
		array_swap_dec(b->array, i);
		b->array[0] = temp;
	}
	write(1, "rrr\n", 4);
}
