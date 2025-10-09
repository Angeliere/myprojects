/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschweit <aschweit@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:43:25 by aschweit       #+#    #+#             */
/*   Updated: 2025/09/30 14:43:27 by aschweit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft.h"

/* Stack structure */
typedef struct s_stack
{
	int	*array;
	int	size;
	int	capacity;
}	t_stack;

typedef struct s_move
{
	int	cost;
	int	index_b;
	int	target_a;
}	t_move;

typedef struct s_push_data
{
	int	*sorted;
	int	original_size;
	int	threshold;
	int	pushed_count;
}	t_push_data;

/* Stack initialization and memory management */
t_stack	*init_stack(int capacity);
int		*array_swap_inc(int *a, int size);
int		*array_swap_dec(int *a, int i);
void	free_stacks(t_stack *a, t_stack *b);

/* Input validation */
int		has_duplicates(t_stack *stack);
int		is_sorted(t_stack *stack);
int		parse_arguments(int argc, char **argv, t_stack *a);
int		count_words(char *str);
int		parse_single_arg(char *str, t_stack *a);
int		*create_sorted_copy(t_stack *a);
int		is_valid_number(char *str);
int		check_overflow(long num);
int		convert_to_number(char *str, int i, long *result);
int		get_sign(char *str, int *i);
int		find_max_in_b(t_stack *b);
int		get_sorted_index(int value, int *sorted, int size);
int		check_overflow(long num);

/* Stack operations */
void	sa(t_stack *a);
void	sb(t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	push_mins_to_b(t_stack *a, t_stack *b);
void	bubble_sort(int *array, int size);
void	copy_array(int *dest, t_stack *src);
void	push_remaining(t_stack *a, t_stack *b, t_push_data *data);
void	push_first_half(t_stack *a, t_stack *b, t_push_data *data);
void	init_push_data(t_push_data *data, t_stack *a);
void	conditional_move(int first, int second, int third, t_stack *a);

/* Sorting algorithms */
void	sort_three(t_stack *a);
void	sort_stack(t_stack *a, t_stack *b);
void	push_back_sorted(t_stack *a, t_stack *b);
void	align_stack(t_stack *a);
void	sort_small(t_stack *a, t_stack *b);
void	push_to_b_optimized(t_stack *a, t_stack *b);
void	push_to_b_simple(t_stack *a, t_stack *b);
void	execute_move(t_move move, t_stack *a, t_stack *b);

/* Helper functions */
int		find_min_index(t_stack *stack);
int		find_max_index(t_stack *stack);
int		find_target_position(int value, t_stack *stack);
int		calculate_rotation_cost(int position, int stack_size);
int		get_rotation_direction(int position, int stack_size);
void	rotate_to_top(t_stack *stack, int index, char stack_name);

t_move	find_cheapest_move(t_stack *a, t_stack *b);
t_move	calculate_move_cost(int idx_b, t_stack *a, t_stack *b);

int		extract_digits(char *str, int *i, char *temp, int *j);
int		extract_sign(char *str, int *i, char *temp, int *j);
int		skip_whitespace(char *str, int *i);
int		add_to_stack(t_stack *a, char *temp);
int		parse_number(char *str, int *value);

#endif
