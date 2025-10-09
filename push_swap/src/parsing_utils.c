/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschweit <aschweit@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 16:12:01 by aschweit       #+#    #+#             */
/*   Updated: 2025/10/04 18:26:50 by aschweit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	skip_whitespace(char *str, int *i)
{
	while (str[*i] == ' ' || str[*i] == '\t' || str[*i] == '\n')
		(*i)++;
	if (!str[*i])
		return (0);
	return (1);
}

int	extract_sign(char *str, int *i, char *temp, int *j)
{
	if (str[*i] == '-' || str[*i] == '+')
		temp[(*j)++] = str[(*i)++];
	if (!str[*i] || str[*i] < '0' || str[*i] > '9')
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}

int	extract_digits(char *str, int *i, char *temp, int *j)
{
	while (str[*i] >= '0' && str[*i] <= '9' && *j < 11)
		temp[(*j)++] = str[(*i)++];
	temp[*j] = '\0';
	return (1);
}

int	add_to_stack(t_stack *a, char *temp)
{
	int	value;

	if (!parse_number(temp, &value))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (a->size >= a->capacity)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	a->array[a->size] = value;
	a->size++;
	return (1);
}
