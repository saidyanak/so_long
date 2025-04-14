#include "so_long.h"

void    init_map(char ** av, t_game game)
{
    game.map = read_map(av[1]);
    if (map_checker(&game))
        return ;
    else
    {
        if (game.map)
            free_map(game.map);
        write(2, "Error\nInvalid Map", 17);
        exit(1);
    }
}