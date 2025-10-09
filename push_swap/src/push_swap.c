/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschweit <aschweit@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:42:54 by aschweit       #+#    #+#             */
/*   Updated: 2025/10/05 15:23:21 by aschweit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_max_element(t_stack *a, t_stack *b)
{
	int	target;

	target = find_target_position(b->array[0], a);
	rotate_to_top(a, target, 'a');
	pa(a, b);
}

void	push_back_sorted(t_stack *a, t_stack *b)
{
	t_move	best_move;
	int		max_idx;
	int		target;

	while (b->size > 0)
	{
		max_idx = find_max_index(b);
		if (max_idx == 0)
			push_max_element(a, b);
		else if (b->size <= 3)
		{
			rotate_to_top(b, max_idx, 'b');
			target = find_target_position(b->array[0], a);
			rotate_to_top(a, target, 'a');
			pa(a, b);
		}
		else
		{
			best_move = find_cheapest_move(a, b);
			execute_move(best_move, a, b);
		}
	}
}

void	sort_stack(t_stack *a, t_stack *b)
{
	if (a->size <= 1 || is_sorted(a))
		return ;
	if (a->size == 2)
	{
		if (a->array[0] > a->array[1])
			sa(a);
		return ;
	}
	if (a->size == 3)
	{
		sort_three(a);
		return ;
	}
	if (a->size <= 5)
	{
		sort_small(a, b);
		return ;
	}
	push_to_b_optimized(a, b);
	sort_three(a);
	push_back_sorted(a, b);
	align_stack(a);
}

int	argument_check(char **argv, int argc, int capacity)
{
	int	has_content;
	int	i;

	if (argc == 2)
	{
		i = 0;
		has_content = 0;
		while (argv[1][i])
		{
			if (argv[1][i] != ' ' && argv[1][i] != '\t' && argv[1][i] != '\n')
			{
				has_content = 1;
				break ;
			}
			i++;
		}
		if (!has_content)
			return (0);
		capacity = count_words(argv[1]);
		if (capacity == 0)
			return (0);
	}
	else
		capacity = argc - 1;
	return (capacity);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		capacity;

	capacity = 0;
	if (argc < 2)
		return (0);
	capacity = argument_check(argv, argc, capacity);
	a = init_stack(capacity);
	b = init_stack(capacity);
	if (!a || !b)
	{
		free_stacks(a, b);
		write(2, "Error\n", 6);
		return (1);
	}
	if (!parse_arguments(argc, argv, a))
	{
		free_stacks(a, b);
		return (1);
	}
	sort_stack(a, b);
	free_stacks(a, b);
	return (0);
}
