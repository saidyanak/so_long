/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syanak <syanak@student.42kocaeli.com.tr >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:35:30 by syanak            #+#    #+#             */
/*   Updated: 2025/04/15 15:25:35 by syanak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>

void	ft_free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}

void	ft_error(char *av, t_game *game)
{
	if (game)
		ft_free_map(game->map);
	write(1, av, ft_strlen(av));
	exit(1);
}

int	mlx_exit(char *str, t_game *game)
{
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->img_player)
		mlx_destroy_image(game->mlx, game->img_player);
	if (game->img_collect)
		mlx_destroy_image(game->mlx, game->img_collect);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_backg)
		mlx_destroy_image(game->mlx, game->img_backg);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	ft_error(str, game);
	return (1);
}

int	close_window(t_game *game)
{
	mlx_exit("Exit", game);
	return (0);
}
