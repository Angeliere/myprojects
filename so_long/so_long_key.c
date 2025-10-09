/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschweit <aschweit@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 15:43:35 by aschweit       #+#    #+#             */
/*   Updated: 2025/09/27 14:01:28 by aschweit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *game)
{
	if (game->map[game->player_x - 1][game->player_y] != '1')
	{
		if (game->map[game->player_x - 1][game->player_y] == 'E')
			if (check_colle(game))
				return ;
		if (game->map[game->player_x - 1][game->player_y] == 'C')
			game->co--;
		game->map[game->player_x][game->player_y] = '0';
		game->map[game->player_x - 1][game->player_y] = 'P';
		game->player_x--;
		game->va++;
		map_rendering(game);
	}
	else
		return ;
	ft_printf("time moved=%d\n", game->va);
}

void	move_down(t_game *game)
{
	if (game->map[game->player_x + 1][game->player_y] != '1')
	{
		if (game->map[game->player_x + 1][game->player_y] == 'E')
			if (check_colle(game))
				return ;
		if (game->map[game->player_x + 1][game->player_y] == 'C')
			game->co--;
		game->map[game->player_x][game->player_y] = '0';
		game->map[game->player_x + 1][game->player_y] = 'P';
		game->player_x++;
		game->va++;
		map_rendering(game);
	}
	else
		return ;
	ft_printf("time moved=%d\n", game->va);
}

void	move_left(t_game *game)
{
	if (game->map[game->player_x][game->player_y - 1] != '1')
	{
		if (game->map[game->player_x][game->player_y - 1] == 'E')
			if (check_colle(game))
				return ;
		if (game->map[game->player_x][game->player_y - 1] == 'C')
			game->co--;
		game->map[game->player_x][game->player_y] = '0';
		game->map[game->player_x][game->player_y - 1] = 'P';
		game->player_y--;
		game->va++;
		map_rendering(game);
	}
	else
		return ;
	ft_printf("time moved=%d\n", game->va);
}

void	move_right(t_game *game)
{
	if (game->map[game->player_x][game->player_y + 1] != '1')
	{
		if (game->map[game->player_x][game->player_y + 1] == 'E')
			if (check_colle(game))
				return ;
		if (game->map[game->player_x][game->player_y + 1] == 'C')
			game->co--;
		game->map[game->player_x][game->player_y] = '0';
		game->map[game->player_x][game->player_y + 1] = 'P';
		game->player_y++;
		game->va++;
		map_rendering(game);
	}
	else
		return ;
	ft_printf("time moved=%d\n", game->va);
}

int	key_handling(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (!game)
	{
		printf("Error: game pointer is NULL!\n");
		return (1);
	}
	if (keycode == 119)
		move_up(game);
	if (keycode == 115)
		move_down(game);
	if (keycode == 97)
		move_left(game);
	if (keycode == 100)
		move_right(game);
	if (keycode == 65307)
		clean_win(game);
	return (0);
}
