/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschweit <aschweit@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 16:40:16 by aschweit       #+#    #+#             */
/*   Updated: 2025/09/30 16:58:08 by aschweit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_path_check(char **map, int x, int y)
{
	if (map[x][y] == '1' || map[x][y] == 'V' || map[x][y] == 'U')
		return ;
	if (map[x][y] == 'E')
	{
		map[x][y] = 'U';
		return ;
	}
	map[x][y] = 'V';
	flood_path_check(map, x + 1, y);
	flood_path_check(map, x - 1, y);
	flood_path_check(map, x, y + 1);
	flood_path_check(map, x, y - 1);
}

int	check_pathing(int x, int y, t_game *game)
{
	char	**dupli_map;

	dupli_map = duplicate_map(game->map);
	if (!dupli_map)
		return (1);
	flood_path_check(dupli_map, x, y);
	x = 0;
	while (dupli_map[x])
	{
		y = 0;
		while (dupli_map[x][y])
		{
			if (dupli_map[x][y] == 'E' || dupli_map[x][y] == 'C')
			{
				ft_printf("ERROR\nUnreachable POI\n");
				free_map(dupli_map);
				return (1);
			}
			y++;
		}
		x++;
	}
	free_map(dupli_map);
	return (0);
}

int	check_colle(t_game *game)
{
	if (game->co == 0)
	{
		ft_printf("Well play\n");
		clean_win(game);
		return (0);
	}
	else
	{
		ft_printf("not all collectible found\n");
		return (1);
	}
}

void	rendering_to_window(t_game *game, int tile_size)
{
	if (game->map[game->i][game->le] == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->wall, game->le * tile_size, game->i * tile_size);
	if (game->map[game->i][game->le] == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			game->floor, game->le * tile_size, game->i * tile_size);
	if (game->map[game->i][game->le] == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->floor, game->le * tile_size, game->i * tile_size);
		mlx_put_image_to_window(game->mlx, game->win,
			game->colle, game->le * tile_size, game->i * tile_size);
	}
	if (game->map[game->i][game->le] == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->exit, game->le * tile_size, game->i * tile_size);
	if (game->map[game->i][game->le] == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->floor, game->le * tile_size, game->i * tile_size);
		mlx_put_image_to_window(game->mlx, game->win,
			game->player, game->le * tile_size, game->i * tile_size);
	}
}

void	map_rendering(t_game *game)
{
	game->i = 0;
	while (game->map[game->i])
	{
		game->le = 0;
		while (game->map[game->i][game->le])
		{
			rendering_to_window(game, game->tile);
			game->le++;
		}
		game->i++;
	}
}
