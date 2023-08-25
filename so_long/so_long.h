/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 11:24:52 by aroca-pa          #+#    #+#             */
/*   Updated: 2023/08/25 20:04:57 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H 

# include <stdio.h>

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





#endif