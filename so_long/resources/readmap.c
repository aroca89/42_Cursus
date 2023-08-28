/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:04:10 by aroca-pa          #+#    #+#             */
/*   Updated: 2023/08/28 20:14:14 by aroca-pa         ###   ########.fr       */
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

