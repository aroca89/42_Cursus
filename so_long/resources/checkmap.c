/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 20:26:13 by aroca-pa          #+#    #+#             */
/*   Updated: 2023/08/25 20:47:21 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include "../so_long.h"
#include <stdio.h>

void map_is_rectangular(t_map *map)
{
    int  first_row_len;
    int row_len;
    int index = 0; // Inicia en 1 para omitir la primera fila que es NULL
    
    first_row_len = ftgnl_strlen(map->data[0]); // Usar el primer elemento
    
    while (map->data[index] != NULL)
    {
        row_len = ftgnl_strlen(map->data[index]);
        
        if (row_len != first_row_len)
        {
            perror("Error: el mapa no es rectangular\n");
            exit(EXIT_FAILURE);
        }
        
        index++;
    }
    // Asignar los valores a los campos de la estructura map
    map->rows = index;
    map->cols = first_row_len -1;
}

void map_closed(t_map *map)
{
    int y;
    int x;

    y = 0;
    x = 1;
    
    printf("map->rows = %d\n", map->rows);
    printf("map->cols = %d\n", map->cols);
    while (map->data[y][x] != '\0')
    {
        //printf("Leyendo borde superior e inferior: %c\n", map->data[y][x - 1]);
        if( map->data[0][x - 1] != '1'  || map->data[map->rows - 1][x - 1] != '1')
        {    
            //printf("Error en posición [%d][%d] = %c\n", y, (x - 1), map->data[y][map->cols - 1]);
            perror("Error\nNo esta cerrado el mapa\n");
            exit(EXIT_FAILURE);
        }
        x++;
    }
    y = 2;
    
    while (map->data[y] != NULL)
    {
        
        //printf("Leyendo borde izquierdo y derecho: %c\n", map->data[y][x]);
        if( map->data[y - 1][0] != '1'|| map->data[y - 1][map->cols - 1] != '1' )
        {   
            
            //printf("Error en posición [%d][%d] = %c\n", y, x, map->data[y][x]);
            perror("Error\nNo esta cerrado el mapa\n");
            exit(EXIT_FAILURE);
        }
        y++;
    }
    //printf("El mapa está cerrado correctamente.\n");
}

void check_points(t_map *map)
{
    int y;
    int x;
    char pixel;

    y = 0;
    while (map->data[y] != NULL)
    {  
        x = 0;
        while(map->data[y][x] != '\0')
        {  
            pixel = map->data[y][x];              
            printf("ERROR: Caracter no reconocido en posición [%d][%d]\n", y, x);
            if( pixel != '1' && pixel != '0' && pixel != 'P' && pixel != 'E' && pixel != 'C' && pixel != '\n')
            {
                perror("ERROR\nCaracter no reconocido");
                exit(EXIT_FAILURE);
            }
            if ( pixel == 'P')
            {
                map->place_start++;
                map->character_position_row = y; // Asignar la fila actual
                map->character_position_col = x; // Asignar la columna actual
            }
            if ( pixel == 'E')
                map->exit++;
            if ( pixel == 'C')
                map->collectibles++;
            x++;
        }
        y++;
    }
    if( map->place_start != 1 || map->exit != 1 || map->collectibles < 1)
    {
        perror("ERROR\nFail check points");
        exit(EXIT_FAILURE);
    }
    printf("map->place_star = %d\n", map->place_start);
    printf("map->exit = %d\n", map->exit);
    printf("map->collectibles = %d\n", map->collectibles);
    printf("Las coordenadas del personaje son (%d, %d)\n", map->character_position_row, map->character_position_col);
    printf("Carácter en las coordenadas del personaje: %c\n", map->data[map->character_position_row][map->character_position_col]);
}

void	ft_floodfill(t_map *map, int x, int y)
{
	if (x >= map->cols || y >= map->rows || x < 0 || y < 0 || map->data[y][x] == '1' || map->data[y][x] == 'X')
		return ;
	else
	{
		map->data[y][x] = 'X';
		ft_floodfill(map, x + 1, y);
		ft_floodfill(map, x - 1, y);
		ft_floodfill(map, x, y + 1);
		ft_floodfill(map, x, y - 1);
	}
	return ;
}

void free_map(t_map *map)
{
    int i = 0;
    
    while (map->data[i] != NULL)
    {
        free(map->data[i]);
        i++;
    }
    free(map->data);
    free(map);
}

