/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:27:07 by aroca-pa          #+#    #+#             */
/*   Updated: 2023/09/07 14:02:24 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx_opengl/mlx.h"
#include "../so_long.h"
#include <stdio.h>

int	key_hook(int keycode, t_map *map)
{
    (void)map;
    printf("Tecla presionada: %d\n", keycode);
    if(keycode == 13 || keycode == 126)
    {
        printf("Me muevo a arriba\n" );
    }
    else if(keycode == 1 || keycode == 125)
        printf("Me muevo a abajo\n" );
    else if(keycode == 0 || keycode == 123)
        printf("Me muevo a la izquierda\n" );
    else if(keycode == 2 || keycode == 124)
        printf("Me muevo a la derecha \n" );
    return(keycode);
}
void conect_hook(t_map *map)
{
    int keycode = 0;
    mlx_key_hook(map->render->mlx_win, key_hook, map);
    if (key_hook(keycode, map) == 13)
    {
        map->data[map->character_position_col][map->character_position_row];
        map->character_position_row--;
    }//mlx_loop(map->render->mlx_win);
}