/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschweit <aschweit@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 13:01:24 by aschweit       #+#    #+#             */
/*   Updated: 2025/10/01 14:09:01 by aschweit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_win(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (!game)
	{
		printf("Error: game pointer is NULL!\n");
		return (1);
	}
	clean_win(game);
	return (0);
}

int	read_ber_map(char *map_file, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(map_file, O_RDONLY);
	game->map = malloc(sizeof(char *) * 1000);
	if (!game->map)
		return (-1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		game->map[game->i] = ft_strdup(line);
		free(line);
		game->i++;
		line = get_next_line(fd);
	}
	game->map[game->i] = NULL;
	game->i = 0;
	check_poi_and_size(game);
	game->i = 0;
	close (fd);
	return (0);
}

void	load_images(void *mlx, t_game *game)
{
	game->floor = mlx_xpm_file_to_image(mlx, "floor.xpm",
			&game->tile, &game->tile);
	check_image(game, game->floor);
	game->wall = mlx_xpm_file_to_image(mlx, "wall.xpm",
			&game->tile, &game->tile);
	check_image(game, game->wall);
	game->colle = mlx_xpm_file_to_image(mlx, "colle.xpm",
			&game->tile, &game->tile);
	check_image(game, game->colle);
	game->exit = mlx_xpm_file_to_image(mlx, "exit.xpm",
			&game->tile, &game->tile);
	check_image(game, game->exit);
	game->player = mlx_xpm_file_to_image(mlx, "player.xpm",
			&game->tile, &game->tile);
	check_image(game, game->player);
	map_rendering(game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	check_arguments(argc);
	error_ber_extension(argv[1]);
	init_game(&game);
	read_ber_map(argv[1], &game);
	if (check_pathing(game.player_x, game.player_y, &game))
	{
		free_map(game.map);
		exit (1);
	}
	game.mlx = mlx_init();
	mlx_get_screen_size(game.mlx, &game.width, &game.height);
	check_map_to_screen(&game);
	game.win = mlx_new_window(game.mlx, (ft_strlen(game.map[0]) * game.tile),
			(end_line(game.map) * game.tile), "so_long");
	load_images(game.mlx, &game);
	mlx_hook(game.win, 17, 0, close_win, &game);
	game.va = 0;
	mlx_key_hook(game.win, key_handling, &game);
	mlx_loop(game.mlx);
}
