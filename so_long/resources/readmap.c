/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:04:10 by aroca-pa          #+#    #+#             */
/*   Updated: 2023/08/22 22:50:21 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

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
    {
        perror("ERROR de memoria\n");
        exit(EXIT_FAILURE);
    }

    if (fd == -1)
    {
        perror("Error al abrir el archivo\n");
        free(map);
        exit(EXIT_FAILURE);
    }

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

char **convert_maps(const char *filename)
{
    int num_lines = len_lines(filename);
    char **map = read_lines(filename, num_lines);

    return map;
}
