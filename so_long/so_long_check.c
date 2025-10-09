/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschweit <aschweit@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 14:50:33 by aschweit       #+#    #+#             */
/*   Updated: 2025/10/01 16:16:57 by aschweit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_wall(t_game *game)
{
	if ((game->map[0][game->le] != '1' || game->map [game->i][0] != '1'
		|| game->map[0][ft_strlen(game->map[0]) - 1] != '1'
		|| game->map[end_line(game->map) - 1][game->le] != '1' ))
	{
		ft_printf("ERROR\nsurrounding wall invalid\n");
		clean_win(game);
	}
}

void	number_poi(t_game *game)
{
	while (game->map[game->i] != NULL)
	{
		while (game->map[game->i][game->le] != '\0')
		{
			if (game->map[game->i][game->le] == 'E')
				game->e++;
			if (game->map[game->i][game->le] == 'P')
			{
				game->player_x = game->i;
				game->player_y = game->le;
				game->p++;
			}
			if (game->map[game->i][game->le] == 'C')
				game->co++;
			check_wall(game);
			check_character(game);
			game->le++;
		}
		game->i++;
		game->le = 0;
	}
	game->i = 0;
}

void	check_poi_and_size(t_game *game)
{
	game->le = 0;
	number_poi(game);
	while (game->map[game->i] != NULL)
	{
		if (ft_strlen(game->map[0]) != ft_strlen(game->map[game->i]))
		{
			ft_printf("ERROR\n line not equal\n");
			free_map(game->map);
			exit (1);
		}
		game->i++;
		if (game->i == (int)(ft_strlen(game->map[0])))
		{
			ft_printf("ERROR\nNot a rectangle\n");
			free_map(game->map);
			exit(0);
		}
	}
	if (game->e >= 2 || game->p >= 2 || game->co < 1)
	{
		ft_printf("ERROR\n number of POI invalide\n");
		free_map(game->map);
		exit (1);
	}
}

void	check_map_to_screen(t_game *game)
{
	if ((end_line(game->map) * game->tile) > game->height
		|| ((int)ft_strlen(game->map[0]) * game->tile) > game->width)
	{
		ft_printf("map too big\n");
		clean_win(game);
	}
}

void	check_image(t_game *game,void *img)
{
	if (!img)
	{
		ft_printf("invalid texture\n");
		clean_win(game);
	}
}
