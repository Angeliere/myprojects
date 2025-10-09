/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschweit <aschweit@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 16:25:41 by aschweit       #+#    #+#             */
/*   Updated: 2025/10/04 18:27:56 by aschweit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*array_swap_inc(int *a, int size)
{
	int	i;

	i = 0;
	while (i < (size - 1))
	{
		a[i] = a[i + 1];
		i++;
	}
	return (a);
}

int	*array_swap_dec(int *a, int i)
{
	while (i > 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	return (a);
}
