/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accessibility_controls.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syanak <syanak@student.42kocaeli.com.tr >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:07:14 by syanak            #+#    #+#             */
/*   Updated: 2025/04/15 15:24:51 by syanak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>

void	xpm_control_one(void)
{
	int	ft_background;
	int	ft_collectibe;
	int	fd_exit;
	int	fd_player;

	ft_background = open("./images/background.xpm", O_RDWR);
	ft_collectibe = open("./images/collectibe.xpm", O_RDWR);
	fd_exit = open("./images/exit.xpm", O_RDWR);
	fd_player = open("./images/player.xpm", O_RDWR);
	if (ft_background <= 0 || ft_collectibe <= 0 || fd_exit <= 0
		|| fd_player <= 0)
	{
		write(1, "Missing XPM File\n", 18);
		close(ft_background);
		close(ft_collectibe);
		close(fd_exit);
		close(fd_player);
		exit(1);
	}
	close(ft_background);
	close(ft_collectibe);
	close(fd_exit);
	close(fd_player);
}

void	xpm_control_two(void)
{
	int	ft_wall;

	ft_wall = open("./images/wall.xpm", O_RDWR);
	if (ft_wall <= 0)
	{
		write(1, "Missing XPM File\n", 18);
		close(ft_wall);
		exit(1);
	}
	close(ft_wall);
}

void	path_checker(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (path[len - 1] != 'r' || path[len - 2] != 'e' || path[len - 3] != 'b'
		|| path[len - 4] != '.')
	{
		write(1, "Wrong File Extension", 21);
		exit(1);
	}
}

void	file_control(char *path)
{
	int	fd;

	fd = open(path, O_RDWR);
	if (fd <= 0)
	{
		write(1, "Wrong File Path", 16);
		close(fd);
		exit(1);
	}
	close(fd);
}

void	accessibility_control(int ac, char **av)
{
	if (ac == 2)
	{
		xpm_control_one();
		xpm_control_two();
		path_checker(av[1]);
		file_control(av[1]);
	}
	else
	{
		write(2, "Accessibility Error", 19);
		exit(1);
	}
}
