/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:04:10 by aroca-pa          #+#    #+#             */
/*   Updated: 2023/09/14 16:16:03 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> // Biblioteca para funcion CLOSE
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "../get_next_line/get_next_line.h"
#include "../libft_42/libft.h"
#include "../so_long.h"

static int	len_lines(const char *filename)
{
	int		fd;
	int		num_lines;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_lst_perror(INVALID_FILE, NULL);
	num_lines = 0;
	while (get_next_line(fd))
		num_lines++;
	close(fd);
	return (num_lines);
}

static	char	**read_lines(const char *filename, int num_lines)
{	
	char	**map;
	int		fd;
	char	*line;
	int		i;

	map = (char **)malloc((num_lines + 1) * sizeof(char *));
	fd = open(filename, O_RDONLY);
	if (!map)
		ft_lst_perror(MALLOC_ERROR, NULL);
	if (fd == -1)
		ft_lst_perror(INVALID_FILE, NULL);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		map[i] = line;
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

void	convert_maps(const char *filename, t_map *map)
{
	char	**map_data;
	int		num_lines;

	num_lines = len_lines(filename);
	if (num_lines == 0)
		ft_lst_perror(1, NULL);
	map_data = read_lines(filename, num_lines);
	map->data = map_data;
}

t_map	*copy_map(t_map *map)
{
	t_map	*map_copy;
	int		i;

	map_copy = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!map_copy)
		ft_lst_perror(MALLOC_ERROR, map_copy);
	*map_copy = *map;
	map_copy->data = (char **)ft_calloc(map->rows + 1, sizeof(char *));
	if (!map_copy->data)
		ft_lst_perror(MALLOC_ERROR, map_copy);
	i = 0;
	while (map->data[i] != NULL)
	{
		map_copy->data[i] = ft_substr(map->data[i], 0, ft_strlen(map->data[i]));
		if (!map_copy->data)
			ft_lst_perror(MALLOC_ERROR, map_copy);
		i++;
	}
	map_copy->data[i] = NULL;
	return (map_copy);
}

void	ft_floodfill(t_map *map, int x, int y)
{
	if (x >= map->cols || y >= map->rows || x < 0 || y < 0 || \
map->data[y][x] == '1' || map->data[y][x] == 'X')
		return ;
	else
	{
		map->data[y][x] = 'X';
		ft_floodfill(map, x + 1, y);
		ft_floodfill(map, x - 1, y);
		ft_floodfill(map, x, y + 1);
		ft_floodfill(map, x, y - 1);
	}
	return ;
}
