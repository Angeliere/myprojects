/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement_operation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschweit <aschweit@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:20:07 by aschweit       #+#    #+#             */
/*   Updated: 2025/10/04 18:29:24 by aschweit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/* Basic operations */
void	sa(t_stack *a)
{
	int	temp;

	if (a->size < 2)
		return ;
	temp = a->array[0];
	a->array[0] = a->array[1];
	a->array[1] = temp;
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	int	temp;

	if (b->size < 2)
		return ;
	temp = b->array[0];
	b->array[0] = b->array[1];
	b->array[1] = temp;
	write(1, "sb\n", 3);
}

void	pa(t_stack *a, t_stack *b)
{
	int	i;

	if (b->size == 0)
		return ;
	i = a->size;
	while (i > 0)
	{
		a->array[i] = a->array[i - 1];
		i--;
	}
	a->array[0] = b->array[0];
	a->size++;
	i = 0;
	while (i < b->size - 1)
	{
		b->array[i] = b->array[i + 1];
		i++;
	}
	b->size--;
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	int	i;

	if (a->size == 0)
		return ;
	i = b->size;
	while (i > 0)
	{
		b->array[i] = b->array[i - 1];
		i--;
	}
	b->array[0] = a->array[0];
	b->size++;
	i = 0;
	while (i < a->size - 1)
	{
		a->array[i] = a->array[i + 1];
		i++;
	}
	a->size--;
	write(1, "pb\n", 3);
}

void	ra(t_stack *a)
{
	int	temp;
	int	i;

	if (a->size < 2)
		return ;
	temp = a->array[0];
	i = 0;
	while (i < a->size - 1)
	{
		a->array[i] = a->array[i + 1];
		i++;
	}
	a->array[a->size - 1] = temp;
	write(1, "ra\n", 3);
}
