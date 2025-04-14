#include "so_long.h" 

int main(int ac, char ** av)
{
    t_game   game;

    accessibility_control(ac, av);
    init_map(av, game);
    //rendenr_map(game);
    //play_game(game);
}