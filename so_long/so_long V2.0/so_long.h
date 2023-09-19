/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 11:24:52 by aroca-pa          #+#    #+#             */
/*   Updated: 2023/09/19 10:50:38 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H 

# include <stdio.h>

# define INVALID_ARGUMENTS 1
# define INVALID_FILE 2
# define INVALID_MAP 3
# define INVALID_EXTENSION 4
# define MALLOC_ERROR 5
# define READ_ERROR 6
# define EMPTY_MAP 7
# define PLAYER_ERROR 8
# define WALL_ERROR 9
# define IMAGE_ERROR 10
# define PLAYER_CANNOT_REACH_EXIT 11

typedef struct s_img
{
	void	*background;
	void	*collectibles;
	void	*exit;
	void	*player;
	void	*wall;	
}			t_img;

typedef struct s_render
{
	void	*mlx;
	void	*mlx_win;
	int		resolution;
	int		window_width;
	int		window_height;
	int		map_offset_x;
	int		map_offset_y;
	int		max_offset_x;
	int		max_offset_y;
}			t_render;

typedef struct s_map
{
	t_render	*render;
	t_img		*img;
	int			rows;
	int			cols;
	int			movements;
	int			collectibles;
	int			exit;
	int			place_start;
	int			character_x;
	int			character_y;
	int			exit_x;
	int			exit_y;
	char		**data;
}				t_map;

void	convert_maps(const char *filename, t_map *map);
void	check_argument(char *argv[]);
int		main(int argc, char *argv[]);
void	print_map(t_map *map);
void	map_is_rectangular(t_map *map);
void	free_map(t_map *map);
void	map_closed(t_map *map);
void	check_points(t_map *map);
void	ft_floodfill(t_map *map, int x, int y);
void	ft_lst_perror(int type, t_map *map);
int		is_map_passable(t_map *map);
t_map	*copy_map(t_map *map);

void	ft_mlx_perror(int type, t_map *map);
void	window_init(t_map *map);
void	render_sprites(t_map *map);
void	cal_render(t_map *map);

void	move_player(t_map *map, int new_col, int new_row, int keycode);
int		key_hook(int keycode, t_map *map);
#endif