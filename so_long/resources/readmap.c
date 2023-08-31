/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:04:10 by aroca-pa          #+#    #+#             */
/*   Updated: 2023/08/30 20:37:22 by aroca-pa         ###   ########.fr       */
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

    if (fd == -1)
    {
        perror("Error al abrir el archivo\n");
        exit(EXIT_FAILURE);
    } 

    while (get_next_line(fd))
        num_lines++;

    close(fd);
    return num_lines;
}

static char **read_lines(const char *filename, int num_lines)
{
    char **map = (char **)malloc((num_lines + 1) * sizeof(char *));
    int fd = open(filename, O_RDONLY);

    if (!map)
        ft_lst_perror(MALLOC_ERROR, NULL);

    if (fd == -1)
        ft_lst_perror(INVALID_FILE, NULL);

    char *line;
    int i = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
        map[i] = line;
        i++;
    }
    map[i] = NULL; // Marca el final de la matriz con NULL

    close(fd);
    return map;
}

t_map *convert_maps(const char *filename)
{
    int num_lines = len_lines(filename);
    char **map_data = read_lines(filename, num_lines);
    
    t_map *map = (t_map *)ft_calloc(1, sizeof(t_map));
    if (!map)
        ft_lst_perror(MALLOC_ERROR, map);
    map->data = map_data; // Asignar el arreglo bidimensional a la estructura
    return map;
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
    
    i = 0;
    // Reservar memoria para el arreglo bidimensional de la copia
    map_copy->data = (char **)ft_calloc(map->rows , sizeof(char *));
    if (!map_copy->data)
        ft_lst_perror(MALLOC_ERROR, map_copy);
    
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
