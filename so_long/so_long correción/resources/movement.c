/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:27:07 by aroca-pa          #+#    #+#             */
/*   Updated: 2023/09/15 19:42:41 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx_opengl/mlx.h"
#include "../so_long.h"
#include "../libft_42/libft.h"
#include <stdio.h>
#include <stdlib.h>

int	key_hook(int keycode, t_map *map)
{
	if (keycode == 53)
	{
		mlx_destroy_window(map->render->mlx, map->render->mlx_win);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == 13 || keycode == 126)
		move_player(map, map->character_y - 1, map->character_x, keycode);
	else if (keycode == 1 || keycode == 125)
		move_player(map, map->character_y + 1, map->character_x, keycode);
	else if (keycode == 0 || keycode == 123)
		move_player(map, map->character_y, map->character_x - 1, keycode);
	else if (keycode == 2 || keycode == 124)
		move_player(map, map->character_y, map->character_x + 1, keycode);
	return (0);
}

static void	move_screen(int keycode, t_map *map)
{
	if (keycode == 13 || keycode == 126)
	{
		if (map->render->map_offset_y > 0)
		{
			map->render->map_offset_y -= 1;
			printf("map_offset_y: %d\n", map->render->map_offset_y);
		}
	}
	else if (keycode == 1 || keycode == 125)
	{
		if (map->render->map_offset_y < map->render->max_offset_y)
		{
			map->render->map_offset_y += 1;
			printf("max_offset_y: %d\n", map->render->max_offset_y);
		}
	}
	else if (keycode == 0 || keycode == 123)
	{
		if (map->render->map_offset_x > 0)
		{
			map->render->map_offset_x -= 1;
			printf("map_offset_x: %d\n", map->render->map_offset_x);
		}
	}
	else if (keycode == 2 || keycode == 124)
	{
		int traba = map->cols - 4;
		if (map->render->map_offset_x < traba)
		{
			map->render->map_offset_x += 1;
			printf("map_offset_x: %d\n", map->render->map_offset_x);
			printf("traba: %d\n", traba);
		}
	}
}



void	move_player(t_map *map, int new_row, int new_col, int keycode)
{
	if (new_row >= 0 && new_row < map->rows && new_col >= 0 && new_col < map->cols)
	{
		if (map->data[new_row][new_col] != '1')
		{
			map->movements++;
			map->data[map->character_y][map->character_x] = '0';
			map->character_x = new_col;
			map->character_y = new_row;
			if (map->data[map->character_y][map->character_x] == 'C')
			{
				map->collectibles--;
			}
			map->data[new_row][new_col] = 'P';
			map->data[map->exit_y][map->exit_x] = 'E';
			move_screen(keycode, map);
			render_map(map);
			if (map->collectibles == 0 && map->data[map->character_y][map->character_x] == 'E')
			{
				mlx_destroy_window(map->render->mlx, map->render->mlx_win);
				exit(EXIT_SUCCESS);
			}
			
		}
	}
}

