/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reachable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syanak <syanak@student.42kocaeli.com.tr >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:07:29 by syanak            #+#    #+#             */
/*   Updated: 2025/04/15 17:01:15 by syanak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_flood_fill(char **map, int x, int y, t_game *game)
{
	if (map[y][x] == 'C')
		game->temp_c--;
	else if (map[y][x] == 'E')
		game->temp_e--;
	if (map[y][x] == '1' || map[y][x] == 'A')
		return ;
	map[y][x] = 'A';
	ft_flood_fill(map, x + 1, y, game);
	ft_flood_fill(map, x - 1, y, game);
	ft_flood_fill(map, x, y + 1, game);
	ft_flood_fill(map, x, y - 1, game);
}

char	**copy_map_allocation(t_game *game)
{
	char	**copy;
	int		i;

	copy = ft_calloc(sizeof(char *), game->map_h + 1);
	if (!copy)
		ft_error("Error\nAlloceted Error!", game);
	i = 0;
	while (i < game->map_h)
	{
		copy[i] = ft_strdup(game->map[i]);
		if (!copy)
		{
			ft_free_map(copy);
			ft_error("Error\nAlloceted error\n", game);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	map_reachable(t_game *game)
{
	char	**tmp_map;

	game->temp_c = game->n_collect;
	game->temp_e = 1;
	tmp_map = copy_map_allocation(game);
	ft_flood_fill(tmp_map, game->x_player, game->y_player, game);
	if (game->temp_c > 0 || game->temp_e > 0)
	{
		ft_free_map(tmp_map);
		ft_error("Error\nMap is not accessible\n", game);
	}
	ft_free_map(tmp_map);
}
