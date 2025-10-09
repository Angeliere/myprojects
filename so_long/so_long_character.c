/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_character.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschweit <aschweit@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:36:08 by aschweit       #+#    #+#             */
/*   Updated: 2025/10/01 14:11:11 by aschweit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_character(t_game *game)
{
	char	c;

	c = game->map[game->i][game->le];
	if (c != 'E' && c != 'P' && c != '1' && c != '0' && c != 'C')
	{
		ft_printf("ERROR\nInvalid character\n");
		clean_win(game);
	}
}

int	check_ber_extension(char *filename)
{
	int	len;

	if (!filename)
		return (0);
	len = ft_strlen(filename);
	if (len < 4)
		return (0);
	if (filename[len - 4] == '.' && filename[len - 3] == 'b'
		&& filename[len - 2] == 'e'
		&& filename[len - 1] == 'r')
		return (1);
	return (0);
}

void	check_arguments(int argc)
{
	if (argc != 2)
	{
		ft_printf("ERROR\ninvalid number of arguments\n");
		exit(1);
	}
}

void	error_ber_extension(char *argv)
{
	if (!check_ber_extension(argv))
	{
		ft_printf("ERROR\nMap file invalide type\n");
		exit(1);
	}
}
