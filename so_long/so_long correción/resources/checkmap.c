/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 20:26:13 by aroca-pa          #+#    #+#             */
/*   Updated: 2023/09/14 16:16:55 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_42/libft.h"
#include "../so_long.h"
#include <stdio.h>

void	map_is_rectangular(t_map *map)
{
	int		first_row_len;
	int		row_len;
	int		index;

	first_row_len = ft_strlen(map->data[0]);
	index = 0;
	while (map->data[index] != NULL)
	{
		row_len = ft_strlen(map->data[index]);
		if (row_len != first_row_len)
			ft_lst_perror(INVALID_MAP, map);
		index++;
	}
	map->rows = index;
	map->cols = first_row_len - 1;
}

void	map_closed(t_map *map)
{
	int		y;
	int		x;

	y = 0;
	x = 1;
	while (map->data[y][x] != '\0')
	{
		if (map->data[0][x - 1] != '1' || \
	map->data[map->rows - 1][x - 1] != '1')
			ft_lst_perror(WALL_ERROR, map);
		x++;
	}
	y = 2;
	x = 0;
	while (map->data[y] != NULL)
	{
		if (map->data[y - 1][0] != '1' || \
	map->data[y - 1][map->cols - 1] != '1')
			ft_lst_perror(WALL_ERROR, map);
		y++;
	}
}

static void	selec_pixel(t_map *map, char pixel, int x, int y)
{
	if (pixel == 'P')
	{
		map->character_x = x;
		map->character_y = y;
		map->place_start++;
	}
	if (pixel == 'E')
	{
		map->exit_x = x;
		map->exit_y = y;
		map->exit++;
	}
	if (pixel == 'C')
		map->collectibles++;
}

void	check_points(t_map *map)
{
	int		y;
	int		x;
	char	pixel;

	y = 0;
	while (map->data[y] != NULL)
	{
		x = 0;
		while (map->data[y][x] != '\0')
		{
			pixel = map->data[y][x];
			if (pixel != '1' && pixel != '0' && pixel != 'P' && pixel != \
'E' && pixel != 'C' && pixel != '\n')
				ft_lst_perror(INVALID_MAP, map);
			selec_pixel(map, pixel, x, y);
			x++;
		}
		y++;
	}
	if (map->place_start != 1 || map->exit != 1 || map->collectibles < 1)
		ft_lst_perror(INVALID_MAP, map);
}

int	is_map_passable(t_map *map)
{
	int		y;
	int		x;

	y = 0;
	while (y < map->rows)
	{
		x = 0;
		while (x < map->cols)
		{
			if (map->data[y][x] != '1' && map->data[y][x] \
		!= 'X' && map->data[y][x] != '0')
			{
				ft_lst_perror(PLAYER_CANNOT_REACH_EXIT, map);
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}
