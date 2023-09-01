/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 20:26:13 by aroca-pa          #+#    #+#             */
/*   Updated: 2023/09/01 20:50:17 by aroca-pa         ###   ########.fr       */
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



void ft_floodfill(t_map *struct_map, int x, int y)
{
    // Verificar si las coordenadas (x, y) están fuera del mapa o en una posición no válida ('1' o 'X')
    if (x >= struct_map->cols || y >= struct_map->rows || x < 0 || y < 0 || struct_map->data[y][x] == '1' || struct_map->data[y][x] == 'X')
        return;
    else
    {
        // Marcar la posición actual con 'X' para indicar que ha sido visitada
        struct_map->data[y][x] = 'X';
        
        // Llamadas recursivas a ft_floodfill para explorar las celdas adyacentes
        ft_floodfill(struct_map, x + 1, y); // Derecha
        ft_floodfill(struct_map, x - 1, y); // Izquierda
        ft_floodfill(struct_map, x, y + 1); // Abajo
        ft_floodfill(struct_map, x, y - 1); // Arriba
    }
    return;
}


int is_map_passable(t_map *struct_map)
{
    int y;
    int x;
    
    y = 0; // Inicializa la variable y para recorrer las filas.
    while (y < struct_map->rows) // Bucle externo para recorrer las filas.
    {
        x = 0; // Inicializa la variable x para recorrer las columnas.
        while (x < struct_map->cols) // Bucle interno para recorrer las columnas.
        {
            if (struct_map->data[y][x] != '1' && struct_map->data[y][x] != 'X') // Comprueba si el carácter no es '1' ni 'X'.
            {
                ft_lst_perror(PLAYER_CANNOT_REACH_EXIT, struct_map); // Muestra un mensaje de error.
                return 0; // Devuelve 0 para indicar que el mapa no es transitable.
            }
            x++; // Incrementa x para pasar al siguiente carácter en la fila.
        }
        y++; // Incrementa y para pasar a la siguiente fila en el mapa.
    } 
    return 1; // Si no se encuentra ningún obstáculo, devuelve 1 indicando que el mapa es transitable.
}




