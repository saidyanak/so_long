/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syanak <syanak@student.42kocaeli.com.tr >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:07:39 by syanak            #+#    #+#             */
/*   Updated: 2025/04/15 13:44:51 by syanak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINLBX_H
# define MINLBX_H

# include "./libs/libft/libft.h"
# include "./libs/minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdlib.h>

# define PIXEL 64

# define W 119
# define A 97
# define S 115
# define D 100
# define ESC 65307

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
	int		temp_c;
	int		temp_e;
	int		moves;
	int		endgame;
}			t_game;

void		accessibility_control(int ac, char **av);
void		init_map(char **av, t_game *game);
int			map_checker(t_game *game);
char		**read_map(char *path);
int			put_mlx(t_game *game);
int			close_window(t_game *game);
void		free_map(char **map);
void		map_reachable(t_game *game);
void		render_map(t_game *game);
int			keyboard(int keycode, t_game *game);
void		ft_error(char *av, t_game *game);
void		ft_free_map(char **map);
int			mlx_exit(char *str, t_game *game);
char		*get_next_line(int fd);

#endif
