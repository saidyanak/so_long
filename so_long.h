#ifndef MINLBX_H
# define MINLBX_H

# include <stdlib.h>
# include <fcntl.h>
# include "./libs/libft/libft.h"

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	void	*img_backg;
	void	*img_wall;
	void	*img_player;
	void	*img_collect;
	void	*img_exit;
	void	*img_losing;
	int		map_w;
	int		map_h;
	int		img_w;
	int		img_h;
	int		n_collect;
	char	*intra_str;
	int		n_player;
	int		n_exit;
	int		x_player;
	int		y_player;
	int     temp_c;
    int     temp_e;
	int		moves;
	int		endgame;
}	t_game;

void    accessibility_control(int ac, char **av);
void    init_map(char ** av, t_game *game);
int	map_checker(t_game *game);
char	**read_map(char *path);
int	put_mlx(t_game *game);
void	free_map(char **map);
void	map_reachable(t_game *game);
void    render_map(t_game *game);
int	keyboard(int keycode, t_game *game);


#endif