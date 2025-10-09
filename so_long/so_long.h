/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschweit <aschweit@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:36:15 by aschweit          #+#    #+#             */
/*   Updated: 2025/09/30 16:58:33 by aschweit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft.h"
# include "mlx.h"

typedef struct s_game
{
	char	**map;
	char	**dupli_map;
	int		player_x;
	int		player_y;
	int		e;
	int		p;
	int		va;
	int		le;
	int		co;
	int		i;
	int		tile;
	int		height;
	int		width;
	void	*mlx;
	void	*win;
	void	*floor;
	void	*wall;
	void	*colle;
	void	*exit;
	void	*player;
}	t_game;

int		key_handling(int keycode, void *param);
int		check_colle(t_game *game);
int		end_line(char **map);
int		check_pathing(int x, int y, t_game *game);
int		check_ber_extension(char *filename);
char	**duplicate_map(char **map);
void	rendering_to_window(t_game *game, int tile_size);
void	load_images(void *mlx, t_game *game);
void	map_rendering(t_game *game);
void	init_game(t_game *game);
void	check_poi_and_size(t_game *game);
void	clean_win(t_game *game);
void	free_map(char **map);
void	check_map_to_screen(t_game *game);
void	check_image(t_game *game,void *img);
void	check_character(t_game *game);
void	check_arguments(int argc);
void	error_ber_extension(char *argv);
#endif
