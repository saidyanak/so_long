/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syanak <syanak@student.42kocaeli.com.tr >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:07:08 by syanak            #+#    #+#             */
/*   Updated: 2025/04/16 17:34:15 by syanak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libs/minilibx-linux/mlx.h"
#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	accessibility_control(ac, av);
	init_map(av, &game);
	render_map(&game);
	mlx_hook(game.win, 2, 1L << 0, keyboard, &game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_loop_hook(game.mlx, put_mlx, &game);
	mlx_loop(game.mlx);
}

