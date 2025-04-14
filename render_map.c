/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syanak <syanak@student.42kocaeli.com.tr >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:07:03 by syanak            #+#    #+#             */
/*   Updated: 2025/04/14 13:42:25 by syanak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libs/minilibx-linux/mlx.h"
#include "so_long.h"
#include <unistd.h>

static int	render(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->map_h)
	{
		x = -1;
		while (++x < game->map_w)
		{
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->img_wall, x
					* PIXEL, y * PIXEL);
			else
				mlx_put_image_to_window(game->mlx, game->win, game->img_backg, x
					* PIXEL, y * PIXEL);
			if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->img_exit, x
					* PIXEL, y * PIXEL);
			else if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->img_collect,
					x * PIXEL, y * PIXEL);
		}
	}
	return (0);
}

int	put_mlx(t_game *game)
{
	render(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img_player,
		game->x_player * PIXEL, game->y_player * PIXEL);
	return (0);
}

void	keyboard_progress(t_game *game)
{
	static long	mv_count = 0;

	write(1, "Moves: ", 7);
	write(1, &mv_count, 4);
	if (game->map[game->y_player][game->x_player] == 'C')
	{
		game->n_collect--;
		game->map[game->y_player][game->x_player] = '0';
	}
	if (game->map[game->y_player][game->x_player] == 'E'
		&& game->n_collect == 0)
		mlx_exit("Win", game);
}

int	keyboard(int keycode, t_game *game)
{
	if (keycode == ESC)
		mlx_exit("img_exit", game);
	else if (keycode == W && game->map[game->y_player
		- 1][game->x_player] != '1')
		game->y_player--;
	else if (keycode == A && game->map[game->y_player][game->x_player
		- 1] != '1')
		game->x_player--;
	else if (keycode == D && game->map[game->y_player][game->x_player
		+ 1] != '1')
		game->x_player++;
	else if (keycode == S && game->map[game->y_player
		+ 1][game->x_player] != '1')
		game->y_player++;
	else
		return (0);
	keyboard_progress(game);
	return (0);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	game->mlx = mlx_init();
	if (!game->mlx)
		mlx_exit("Error\nMlx not initialize\n", game);
	game->win = mlx_new_window(game->mlx, game->map_w * PIXEL, game->map_h
			* PIXEL, "so_long");
	game->img_player = mlx_xpm_file_to_image(game->mlx,
			"textures/forest-game-player.xpm", &y, &x);
	game->img_collect = mlx_xpm_file_to_image(game->mlx,
			"textures/forest-game-collectable.xpm", &y, &x);
	game->img_exit = mlx_xpm_file_to_image(game->mlx,
			"textures/forest-game-img_exit.xpm", &y, &x);
	game->img_wall = mlx_xpm_file_to_image(game->mlx,
			"textures/forest-game-img_wall.xpm", &y, &x);
	game->img_backg = mlx_xpm_file_to_image(game->mlx,
			"textures/forest-game-floor.xpm", &y, &x);
	if (!game->win || !game->img_player || !game->img_collect || !game->img_exit
		|| !game->img_wall || !game->img_backg)
		mlx_exit("Error\nTextures not loaded!", game);
}
