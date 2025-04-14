#include "so_long.h"

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

void    init_map(char ** av, t_game *game)
{
    game->map = read_map(av[1]);
    if (map_checker(game))
    {
        ft_map_height(game->map, game);
        ft_find_player(game);
        map_reachable(game);
    }
    else
    {
        if (game->map)
            free_map(game->map);
        write(2, "Error\nInvalid Map", 17);
        exit(1);
    }
}