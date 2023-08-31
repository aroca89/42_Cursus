/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 11:24:52 by aroca-pa          #+#    #+#             */
/*   Updated: 2023/08/31 20:13:46 by aroca-pa         ###   ########.fr       */
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

typedef struct s_map
{
    int         rows;
    int         cols;
    int         collectibles;
    int         exit;
    int         place_start;
    int         character_position_row;
    int         character_position_col;
    char        **data;
}               t_map;

t_map *convert_maps(const char *filename);
void check_argument(char *argv[]);
int main(int argc, char *argv[]);
void print_map(t_map *map);
void map_is_rectangular(t_map *map);
void free_map(t_map *map);
void map_closed(t_map *map);
void check_points(t_map *map);
void	ft_floodfill(t_map *map, int x, int y);
void ft_lst_perror(int type, t_map *map);
void is_map_passable(t_map *map);
t_map *copy_map(t_map *map);





#endif