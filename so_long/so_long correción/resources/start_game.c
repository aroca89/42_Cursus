/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 16:18:44 by aroca-pa          #+#    #+#             */
/*   Updated: 2023/09/14 20:37:08 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_42/libft.h"
#include  "../minilibx_opengl/mlx.h"
#include "../so_long.h"

void	window_init(t_map *map)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	if (!mlx)
		ft_mlx_perror(1, map);
	mlx_win = mlx_new_window(mlx, map->render->window_width, \
map->render->window_height, "So_Long");
	if (!mlx_win)
		ft_mlx_perror(1, map);
	map->render->mlx = mlx;
	map->render->mlx_win = mlx_win;
	render_sprites(map);
	render_map(map);
	mlx_key_hook(map->render->mlx_win, key_hook, map);
	mlx_hook(map->render->mlx_win, 17, 0, (void *)exit, map);
	return ;
}

void	render_sprites(t_map *map)
{
	int	img_size;

	map->img->background = mlx_xpm_file_to_image(map->render->mlx, \
	"textures/backgroun.xpm", &img_size, &img_size);
	if (!map->img->background)
		ft_mlx_perror(4, map);
	map->img->collectibles = mlx_xpm_file_to_image(map->render->mlx, \
	"textures/collectibles.xpm", &img_size, &img_size);
	if (!map->img->collectibles)
		ft_mlx_perror(5, map);
	map->img->exit = mlx_xpm_file_to_image(map->render->mlx, \
	"textures/exit.xpm", &img_size, &img_size);
	if (!map->img->exit)
		ft_mlx_perror(6, map);
	map->img->player = mlx_xpm_file_to_image(map->render->mlx, \
	"textures/player.xpm", &img_size, &img_size);
	if (!map->img->player)
		ft_mlx_perror(7, map);
	map->img->wall = mlx_xpm_file_to_image(map->render->mlx, \
	"textures/wall.xpm", &img_size, &img_size);
	if (!map->img->wall)
		ft_mlx_perror(8, map);
}

void	static	select_put_img(t_map *map, int render_x, int render_y, char c)
{
	if (c == '1')
		mlx_put_image_to_window(map->render->mlx, map->render->mlx_win, \
	map->img->wall, render_x, render_y);
	else if (c == 'C')
		mlx_put_image_to_window(map->render->mlx, map->render->mlx_win, \
	map->img->collectibles, render_x, render_y);
	if (c == 'E')
	{
		mlx_put_image_to_window(map->render->mlx, map->render->mlx_win, \
	map->img->exit, render_x, render_y);
		if (map->character_x == map->exit_x && map->character_y == map->exit_y)
			mlx_put_image_to_window(map->render->mlx, map->render->mlx_win, \
	map->img->player, render_x, render_y);
	}
	if (c == 'P')
		mlx_put_image_to_window(map->render->mlx, map->render->mlx_win, \
	map->img->player, render_x, render_y);
}

void render_map(t_map *map)
{
	int render_x;
	int render_y;
	char character;
	int x;
	int y;

	y = map->render->map_offset_y;
	while (y < map->rows && y - map->render->map_offset_y < map->render->window_height)
	{
		x = map->render->map_offset_x;
		while (x < map->cols && x - map->render->map_offset_x < map->render->window_width)
		{
			render_x = (x - map->render->map_offset_x) * map->render->resolution;
			render_y = (y - map->render->map_offset_y) * map->render->resolution;
			if (render_x >= 0 && render_x < map->render->window_width && render_y >= 0 && render_y < map->render->window_height)
			{
				mlx_put_image_to_window(map->render->mlx, map->render->mlx_win, map->img->background, render_x, render_y);
				character = map->data[y][x];
				select_put_img(map, render_x, render_y, character);
			}
			x++;
		}
		y++;
	}
}
