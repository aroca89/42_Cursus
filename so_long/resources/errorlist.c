/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorlist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:22:36 by aroca-pa          #+#    #+#             */
/*   Updated: 2023/08/31 19:56:47 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdlib.h>

void ft_lst_perror(int type, t_map *map)
{
    // Comprobar el tipo de error y mostrar el mensaje correspondiente
    if (type == 1)
        perror("Wrong number of arguments.\n");
    else if (type == INVALID_FILE)
        perror("Error\nNo such file or directory\n");
    else if (type == INVALID_MAP)
        perror("Error\nInvalid map.Make sure the map is rectangle and is formed only by: '0', '1', 'E', 'P' and 'C'\n");
    else if (type == INVALID_EXTENSION)
        perror("Error.\nInvalid file extension. Make sure it is '.ber'.\n");
    else if (type == MALLOC_ERROR)
        perror("Error.\nFailed to allocate memory.\n");
    else if (type == EMPTY_MAP)
        perror("Error.\nThe file is empty.\n");
    else if (type == PLAYER_ERROR)
        perror("Error.\nThere are two or more player positions.\n");
    else if (type == WALL_ERROR)
        perror("Error\nThe map is not closed by '1'.\n");
    else if (type == IMAGE_ERROR)
        perror("Error.\nThe image is not xpm.\n");
    else if (type ==  PLAYER_CANNOT_REACH_EXIT)
        perror("Error.\nAn inaccessible cell was found\n")

    // Liberar la memoria asignada al mapa
    free_map(map);

    // Salir del programa con un código de error
    exit(-1);
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
