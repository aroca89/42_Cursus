/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:04:10 by aroca-pa          #+#    #+#             */
/*   Updated: 2023/09/05 17:43:13 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> // Biblioteca para funcion CLOSE
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "../get_next_line/get_next_line.h"
#include "../libft_42/libft.h"
#include "../so_long.h"

static int len_lines(const char *filename)
{ 
    int num_lines = 0;
    int fd = open(filename, O_RDONLY);

    // Verificar si se pudo abrir el archivo
    if (fd == -1)
        ft_lst_perror(INVALID_FILE, NULL);

    // Contar el número de líneas en el archivo usando 'get_next_line'
    while (get_next_line(fd))
        num_lines++;

    // Cerrar el archivo después de haber contado las líneas
    close(fd);

    // Devolver el número total de líneas en el archivo
    return num_lines;
}


static char **read_lines(const char *filename, int num_lines)
{
    // Reservar memoria para un arreglo de punteros a caracteres (líneas del mapa)
    char **map = (char **)malloc((num_lines + 1) * sizeof(char *));
    int fd = open(filename, O_RDONLY);

    // Verificar si se asignó memoria correctamente para 'map'
    if (!map)
        ft_lst_perror(MALLOC_ERROR, NULL);

    // Verificar si se pudo abrir el archivo
    if (fd == -1)
        ft_lst_perror(INVALID_FILE, NULL);

    char *line;
    int i = 0;
    // Leer cada línea del archivo usando la función 'get_next_line'
    while ((line = get_next_line(fd)) != NULL)
    {
        // Asignar la línea leída al elemento 'i' del arreglo bidimensional 'map'
        map[i] = line;
        i++;
    }
    map[i] = NULL; // Marcar el final del arreglo con un puntero NULL

    // Cerrar el archivo después de haber leído todas las líneas
    close(fd);

    // Devolver el arreglo bidimensional 'map' que contiene las líneas del archivo
    return map;
}


void convert_maps(const char *filename, t_map *map)
{
    // Obtener el número de líneas en el archivo
    int num_lines; 
    
    num_lines = len_lines(filename);
    if (num_lines == 0)
        ft_lst_perror(1, NULL);

    // Leer las líneas del archivo y almacenarlas en un arreglo bidimensional
    char **map_data = read_lines(filename, num_lines);
    
    
    
    // Asignar el arreglo bidimensional 'map_data' al campo 'data' de la estructura 'map'
    map->data = map_data;
    
    // Devolver el puntero a la estructura t_map que contiene los datos del mapa
}


t_map *copy_map(t_map *map)
{
    int i;
    t_map *map_copy;
    
    // Reservar memoria para la estructura de la copia
    map_copy = (t_map *)ft_calloc(1, sizeof(t_map));
    if (!map_copy)
        ft_lst_perror(MALLOC_ERROR, map_copy);
    
    // Copiar todos los campos de la estructura original a la copia
    *map_copy = *map;
    
    
    // Reservar memoria para el arreglo bidimensional de la copia
    map_copy->data = (char **)ft_calloc(map->rows + 1 , sizeof(char *));
    if (!map_copy->data)
        ft_lst_perror(MALLOC_ERROR, map_copy);
    i = 0;
    // Copiar cada fila del arreglo bidimensional
    while (map->data[i] != NULL)
    {
        // Usar ft_substr para copiar la fila
        map_copy->data[i] = ft_substr(map->data[i], 0, ft_strlen(map->data[i]));
        if (!map_copy->data)
            ft_lst_perror(MALLOC_ERROR, map_copy);
        i++;
    }
    
    // Marcar el final de la matriz en la copia
    map_copy->data[i] = NULL;
    
    return map_copy;
}
