/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 20:26:13 by aroca-pa          #+#    #+#             */
/*   Updated: 2023/08/23 22:15:59 by aroca-pa         ###   ########.fr       */
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
    map->cols = first_row_len; 
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

