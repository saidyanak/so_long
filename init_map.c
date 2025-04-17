/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syanak <syanak@student.42kocaeli.com.tr >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:07:21 by syanak            #+#    #+#             */
/*   Updated: 2025/04/16 11:57:12 by syanak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

void	set_defaults(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->map = NULL;
	game->img_backg = NULL;
	game->img_wall = NULL;
	game->img_player = NULL;
	game->img_collect = NULL;
	game->img_exit = NULL;
	game->img_losing = NULL;
	game->map_w = 0;
	game->map_h = 0;
	game->img_w = 0;
	game->img_h = 0;
	game->n_collect = 0;
	game->intra_str = NULL;
	game->n_player = 0;
	game->n_exit = 0;
	game->x_player = 0;
	game->y_player = 0;
	game->temp_c = 0;
	game->temp_e = 0;
	game->moves = 0;
	game->endgame = 0;
}

static void	ft_find_player(t_game *game)
{
	int		i;
	int		j;
	char	**tmp_map;

	tmp_map = game->map;
	i = 0;
	while (tmp_map[i])
	{
		j = 0;
		while (tmp_map[i][j])
		{
			if (tmp_map[i][j] == 'P')
			{
				game->x_player = j;
				game->y_player = i;
			}
			j++;
		}
		i++;
	}
}

static void	ft_map_height(char **map, t_game *game)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	game->map_h = i;
	i = 0;
	while (map[0][i])
		i++;
	game->map_w = i;
}

void	ft_control_null_map(char *path)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error\nFd open Error\n", 20);
		exit(1);
	}
	line = get_next_line(fd);
	if (!line)
	{
		write(2, "Error\nNULL Map\n", 15);
		close(fd);
		free(line);
		exit(1);
	}
	free(line);
	close(fd);
}

void	init_map(char **av, t_game *game)
{
	set_defaults(game);
	ft_control_null_map(av[1]);
	game->map = read_map(av[1]);
	if (!game->map)
	{
		write(2, "Error\nInvalid Map\n", 18);
		exit(1);
	}
	if (map_checker(game))
	{
		ft_map_height(game->map, game);
		ft_find_player(game);
		map_reachable(game);
	}
	else
	{
		if (game->map)
			ft_free_map(game->map);
		write(2, "Error\nInvalid Map\n", 18);
		exit(1);
	}
}
