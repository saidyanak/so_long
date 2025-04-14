#include "so_long.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:07:48 by yuocak            #+#    #+#             */
/*   Updated: 2025/04/12 19:11:04 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../minilibx/mlx.h"
#include "so_long.h"

static int	render(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->map->height)
	{
		x = -1;
		while (++x < game->map->width)
		{
			if (game->map->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->wall, x
					* PIXEL, y * PIXEL);
			else
				mlx_put_image_to_window(game->mlx, game->win, game->background,
					x * PIXEL, y * PIXEL);
			if (game->map->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->exit, x
					* PIXEL, y * PIXEL);
			else if (game->map->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->coin, x
					* PIXEL, y * PIXEL);
		}
	}
	return (0);
}

int	put_mlx(t_game *game)
{
	render(game);
	mlx_put_image_to_window(game->mlx, game->win, game->player, game->player_x
		* PIXEL, game->player_y * PIXEL);
	return (0);
}

static void	keyboard_progress(t_game *game)
{
	ft_printf("Moves: %d\n", ++game->mv_count);
	if (game->map->map[game->player_y][game->player_x] == 'C')
	{
		game->c_count--;
		game->map->map[game->player_y][game->player_x] = '0';
	}
	if (game->map->map[game->player_y][game->player_x] == 'E'
		&& game->c_count == 0)
		mlx_exit("Win", game);
}

int	keyboard(int keycode, t_game *game)
{
	if (keycode == ESC)
		mlx_exit("Exit", game);
	else if (keycode == W && game->map->map[game->player_y - 1]
		[game->player_x] != '1')
		game->player_y--;
	else if (keycode == A && game->map->map[game->player_y][game->player_x
		- 1] != '1')
		game->player_x--;
	else if (keycode == D && game->map->map[game->player_y][game->player_x
		+ 1] != '1')
		game->player_x++;
	else if (keycode == S && game->map->map[game->player_y
			+ 1][game->player_x] != '1')
		game->player_y++;
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
	game->win = mlx_new_window(game->mlx, game->map->width * PIXEL,
			game->map->height * PIXEL, "so_long");
	game->player = mlx_xpm_file_to_image(game->mlx, "textures/forest-game-player.xpm", &y,
			&x);
	game->coin = mlx_xpm_file_to_image(game->mlx, "textures/forest-game-collectable.xpm", &y, &x);
	game->exit = mlx_xpm_file_to_image(game->mlx, "textures/forest-game-exit.xpm", &y, &x);
	game->wall = mlx_xpm_file_to_image(game->mlx, "textures/forest-game-wall.xpm", &y, &x);
	game->background = mlx_xpm_file_to_image(game->mlx, "textures/forest-game-floor.xpm",
			&y, &x);
	if (!game->win || !game->player || !game->coin || !game->exit || !game->wall
		|| !game->background)
		mlx_exit("Error\nTextures not loaded!", game);
}
