/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschweit <aschweit@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 14:33:28 by aschweit       #+#    #+#             */
/*   Updated: 2025/09/28 16:23:36 by aschweit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	end_line(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		i++;
	}
	return (i);
}

char	**duplicate_map(char **map)
{
	char	**duplicate_map;
	int		i;
	int		rows;

	rows = 0;
	i = 0;
	while (map[rows])
		rows++;
	duplicate_map = malloc(sizeof(char *) * (rows + 1));
	if (!duplicate_map)
		return (NULL);
	while (i < rows)
	{
		duplicate_map[i] = ft_strdup(map[i]);
		i++;
	}
	duplicate_map[i] = NULL;
	return (duplicate_map);
}

void	init_game(t_game *game)
{
	game->player_x = 0;
	game->player_y = 0;
	game->le = 0;
	game->e = 0;
	game->p = 0;
	game->co = 0;
	game->va = 0;
	game->i = 0;
	game->tile = 32;
	game->width = 0;
	game->height = 0;
	game->floor = NULL;
	game->wall = NULL;
	game->colle = NULL;
	game->exit = NULL;
	game->player = NULL;
	game->mlx = NULL;
	game->win = NULL;
}

void	clean_win(t_game *game)
{
	if (game->floor)
		mlx_destroy_image(game->mlx, game->floor);
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->colle)
		mlx_destroy_image(game->mlx, game->colle);
	if (game->exit)
		mlx_destroy_image(game->mlx, game->exit);
	if (game->player)
		mlx_destroy_image(game->mlx, game->player);
	if (game->win)
	{
		mlx_destroy_window(game->mlx, game->win);
	}
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_map(game->map);
	exit(0);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
