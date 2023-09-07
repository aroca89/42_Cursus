/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:27:07 by aroca-pa          #+#    #+#             */
/*   Updated: 2023/09/07 15:20:50 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx_opengl/mlx.h"
#include "../so_long.h"
#include <stdio.h>
#include <stdlib.h>

int key_hook(int keycode, t_map *map)
{
    // Mover al jugador según la tecla presionada
    if (keycode == 53)
    {
        // Cerrar la ventana y salir de la aplicación
        mlx_destroy_window(map->render->mlx, map->render->mlx_win);
        exit(EXIT_SUCCESS);
    }
    else if (keycode == 13 || keycode == 126) // Tecla arriba
    {
        move_player(map, map->character_position_col - 1, map->character_position_row);
    }
    else if (keycode == 1 || keycode == 125) // Tecla abajo
    {
        move_player(map, map->character_position_col + 1, map->character_position_row);
    }
    else if (keycode == 0 || keycode == 123) // Tecla izquierda
    {
        move_player(map, map->character_position_col, map->character_position_row - 1);
    }
    else if (keycode == 2 || keycode == 124) // Tecla derecha
    {
        move_player(map, map->character_position_col, map->character_position_row + 1);
    }

    return (0);
}

void move_player(t_map *map, int new_col, int new_row)
{
    // Verifica si la nueva posición es válida antes de mover al jugador
    if (map->data[new_col][new_col] == 'E')
    {
        // Cerrar la ventana y salir de la aplicación
        mlx_destroy_window(map->render->mlx, map->render->mlx_win);
        exit(EXIT_SUCCESS);
    }
    else if (map->data[new_col][new_row] != '1') {
        // Borra la posición anterior del jugador en la matriz de datos
        map->data[map->character_position_col][map->character_position_row] = '0';

        // Actualiza la posición del jugador
        map->character_position_col = new_col;
        map->character_position_row = new_row;

        // Dibuja al jugador en la nueva posición
        map->data[new_col][new_row] = 'P';

        // Vuelve a renderizar la ventana con la nueva posición del jugador
        render_map(map);
    }
    
}