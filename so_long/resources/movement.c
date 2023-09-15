/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:27:07 by aroca-pa          #+#    #+#             */
/*   Updated: 2023/09/15 12:12:16 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx_opengl/mlx.h"
#include "../so_long.h"
#include "../ft_printf/ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

int	key_hook(int keycode, t_map *map)
{
	// Calcula los desplazamientos máximos permitidos en X e Y
	int max_offset_x = map->cols * map->render->resolution - map->render->window_width;
	int max_offset_y = map->rows * map->render->resolution - map->render->window_height;

	if (keycode == 53)
	{
		// Tecla "Esc" presionada: cierra la ventana y sale del programa
		mlx_destroy_window(map->render->mlx, map->render->mlx_win);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == 13 || keycode == 126)
	{
		// Tecla "W" o flecha arriba: intenta mover al jugador hacia arriba
		if (move_player(map, map->character_y - 1, map->character_x))
		{
			// Si el movimiento fue válido, ajusta el desplazamiento vertical de la ventana si es posible
			if (map->render->map_offset_y > 0)
				map->render->map_offset_y -= 1;
		}
	}
	else if (keycode == 1 || keycode == 125)
	{
		// Tecla "S" o flecha abajo: intenta mover al jugador hacia abajo
		if (move_player(map, map->character_y + 1, map->character_x))
		{
			// Ajusta el desplazamiento vertical de la ventana si es posible
			if (map->render->map_offset_y < max_offset_y)
				map->render->map_offset_y += 1;
		}
	}
	else if (keycode == 0 || keycode == 123)
	{
		// Tecla "A" o flecha izquierda: intenta mover al jugador hacia la izquierda
		if (move_player(map, map->character_y, map->character_x - 1))
		{
			// Ajusta el desplazamiento horizontal de la ventana si es posible
			if (map->render->map_offset_x > 0)
				map->render->map_offset_x -= 1;
		}
	}
	else if (keycode == 2 || keycode == 124)
	{
		// Tecla "D" o flecha derecha: intenta mover al jugador hacia la derecha
		if (move_player(map, map->character_y, map->character_x + 1))
		{
			// Ajusta el desplazamiento horizontal de la ventana si es posible
			if (map->render->map_offset_x < max_offset_x)
				map->render->map_offset_x += 1;
		}
	}
	return (0);
}

int move_player(t_map *map, int new_row, int new_col)
{
	if (new_row >= 0 && new_row < map->rows && new_col >= 0 && new_col < map->cols)
	{
		// Verifica si la nueva posición es válida en el mapa
		if (map->data[new_row][new_col] != '1')
		{
			// Realiza el movimiento del jugador y actualiza el mapa
			map->movements++;
			map->data[map->character_y][map->character_x] = '0';
			map->character_x = new_col;
			map->character_y = new_row;
			if (map->data[map->character_y][map->character_x] == 'C')
			{
				// Si recoge un objeto "C", actualiza la cuenta de objetos recolectados
				map->collectibles--;
			}
			map->data[new_row][new_col] = 'P';
			map->data[map->exit_y][map->exit_x] = 'E';

			render_map(map);
			if (map->collectibles == 0 && map->data[map->character_y][map->character_x] == 'E')
			{
				// Si se recogen todos los objetos y se llega a la salida "E", el juego termina
				mlx_destroy_window(map->render->mlx, map->render->mlx_win);
				exit(EXIT_SUCCESS);
			}
		}
		return 1;
	}
	return 0;
}
