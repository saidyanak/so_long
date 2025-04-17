/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syanak <syanak@student.42kocaeli.com.tr >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:07:32 by syanak            #+#    #+#             */
/*   Updated: 2025/04/16 11:50:25 by syanak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

void	check_double_nl(char *line, int fd)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n' && (line[i + 1] == '\n' || line[1] == '\0'))
		{
			write(1, "Error\nMap is not rectangular\n", 29);
			free(line);
			close(fd);
			exit(1);
		}
		i++;
	}
}

char	**read_map(char *path)
{
	int		fd;
	char	*line;
	char	*holder_map;
	char	*holder;
	char	**map;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	holder_map = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		holder = holder_map;
		holder_map = ft_strjoin(holder, line);
		free(line);
		free(holder);
	}
	check_double_nl(holder_map, fd);
	map = ft_split(holder_map, '\n');
	return (free(holder_map), close(fd), map);
}
