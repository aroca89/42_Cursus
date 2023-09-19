/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 11:24:48 by aroca-pa          #+#    #+#             */
/*   Updated: 2023/09/19 10:17:58 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../libft_42/libft.h"
#include <stdlib.h>
#include  "../minilibx_opengl/mlx.h"

static t_map	*ft_init_struct(void)
{
	t_map	*map;

	map = (t_map *) calloc(1, sizeof(t_map));
	if (!map)
		ft_lst_perror(MALLOC_ERROR, NULL);
	map->rows = 0;
	map->cols = 0;
	map->movements = 0;
	map->collectibles = 0;
	map->exit = 0;
	map->place_start = 0;
	map->character_x = 0;
	map->character_y = 0;
	map->exit_x = 0;
	map->exit_y = 0;
	map->data = NULL;
	return (map);
}

static void	ft_init_struct_render(t_map *map)
{
	map->render = (t_render *)calloc(1, sizeof(t_render));
	if (!map->render)
		ft_lst_perror(MALLOC_ERROR, map);
	map->render->mlx = NULL;
	map->render->mlx_win = NULL;
	map->render->resolution = 64;
	map->render->window_width = map->render->resolution * 8;
	map->render->window_height = map->render->resolution * 6;
	map->render->map_offset_y = 0;
	map->render->map_offset_x = 0;
	map->render->max_offset_x = map->render->map_offset_x * \
map->render->resolution - map->render->window_width;
	map->render->max_offset_y = map->render->map_offset_y * \
map->render->resolution - map->render->window_height;
	map->img = (t_img *)calloc(1, sizeof(t_img));
	if (!map->img)
		ft_lst_perror(MALLOC_ERROR, map);
	map->img->background = NULL;
	map->img->collectibles = NULL;
	map->img->exit = NULL;
	map->img->player = NULL;
	map->img->wall = NULL;
}

int	main(int argc, char *argv[])
{
	t_map	*map;
	t_map	*map_copy;

	if (argc == 2)
	{
		check_argument(argv);
		map = ft_init_struct();
		convert_maps(argv[1], map);
		map_is_rectangular(map);
		map_closed(map);
		check_points(map);
		map_copy = copy_map(map);
		ft_floodfill(map_copy, map_copy->character_x, map_copy->character_y);
		if (is_map_passable(map_copy) == 1)
			free_map(map_copy);
		ft_init_struct_render(map);
		window_init(map);
		mlx_loop(map->render->mlx);
		return (EXIT_SUCCESS);
	}
	else
		ft_lst_perror(INVALID_ARGUMENTS, NULL);
	return (EXIT_SUCCESS);
}
