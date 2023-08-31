/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 20:26:13 by aroca-pa          #+#    #+#             */
/*   Updated: 2023/08/31 18:52:20 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_42/libft.h"
#include "../so_long.h"
#include <stdio.h>

void map_is_rectangular(t_map *map)
{
    int  first_row_len;
    int row_len;
    int index = 0;
    
    // Obtener la longitud de la primera fila
    first_row_len = ft_strlen(map->data[0]); // Usar el primer elemento
    
    // Iterar a través de las filas del mapa
    while (map->data[index] != NULL)
    {
        // Obtener la longitud de la fila actual
        row_len = ft_strlen(map->data[index]);
        
        // Comprobar si la longitud de la fila actual es diferente a la longitud de la primera fila
        if (row_len != first_row_len)
            ft_lst_perror(INVALID_MAP, map); // Si no es rectangular, mostrar un mensaje de error y salir
        index++;
    }
    
    // Asignar los valores de filas y columnas a la estructura del mapa
    map->rows = index;
    map->cols = first_row_len - 1;
}


void map_closed(t_map *map)
{
    int y;
    int x;

    y = 0;
    x = 1;
    
    // Comprobar el borde superior e inferior
    while (map->data[y][x] != '\0')
    {
        // Verificar si el borde superior e inferior contiene '1'
        if (map->data[0][x - 1] != '1' || map->data[map->rows - 1][x - 1] != '1')
            ft_lst_perror(WALL_ERROR, map); // Si no está cerrado, mostrar un mensaje de error y salir
        x++;
    }
    
    // Reiniciar valores
    y = 2;
    x = 0;
    
    // Comprobar el borde izquierdo y derecho
    while (map->data[y] != NULL)
    {
        // Verificar si el borde izquierdo y derecho contiene '1'
        if (map->data[y - 1][0] != '1' || map->data[y - 1][map->cols - 1] != '1')  
            ft_lst_perror(WALL_ERROR, map); // Si no está cerrado, mostrar un mensaje de error y salir
        y++;
    }
    // El mapa está cerrado correctamente
}


void check_points(t_map *map)
{
    int y;
    int x;
    char pixel;

    y = 0;
    // Recorrer filas del mapa
    while (map->data[y] != NULL)
    {  
        x = 0;
        // Recorrer caracteres en una fila
        while(map->data[y][x] != '\0')
        {  
            pixel = map->data[y][x];              
            // Verificar si el pixel no es uno de los caracteres permitidos
            if (pixel != '1' && pixel != '0' && pixel != 'P' && pixel != 'E' && pixel != 'C' && pixel != '\n')
                ft_lst_perror(INVALID_MAP, map);
            // Contar el número de elementos 'P', 'E' y 'C'
            if (pixel == 'P')
            {
                map->place_start++;
                map->character_position_row = y; // Asignar la fila actual
                map->character_position_col = x; // Asignar la columna actual
            }
            if (pixel == 'E')
                map->exit++;
            if (pixel == 'C')
                map->collectibles++;
            x++;
        }
        y++;
    }
    // Verificar si hay exactamente un punto de partida ('P'), una salida ('E') y al menos un coleccionable ('C')
    if (map->place_start != 1 || map->exit != 1 || map->collectibles < 1)
        ft_lst_perror(INVALID_MAP, map);
}



void ft_floodfill(t_map *map, int x, int y)
{
    // Verificar si las coordenadas (x, y) están fuera del mapa o en una posición no válida ('1' o 'X')
    if (x >= map->cols || y >= map->rows || x < 0 || y < 0 || map->data[y][x] == '1' || map->data[y][x] == 'X')
        return;
    else
    {
        // Marcar la posición actual con 'X' para indicar que ha sido visitada
        map->data[y][x] = 'X';
        
        // Llamadas recursivas a ft_floodfill para explorar las celdas adyacentes
        ft_floodfill(map, x + 1, y); // Derecha
        ft_floodfill(map, x - 1, y); // Izquierda
        ft_floodfill(map, x, y + 1); // Abajo
        ft_floodfill(map, x, y - 1); // Arriba
    }
    return;
}


void free_map(t_map *map)
{
    int i = 0;
    
    // Liberar la memoria asignada a cada fila del arreglo bidimensional 'data'
    while (map->data[i] != NULL)
    {
        free(map->data[i]);
        i++;
    }
    
    // Liberar la memoria asignada al arreglo de punteros 'data' y a la estructura 'map' en sí
    free(map->data);
    free(map);
}


