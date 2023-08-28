/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorlist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:22:36 by aroca-pa          #+#    #+#             */
/*   Updated: 2023/08/28 17:40:22 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdlib.h>

void ft_lst_perror(int type, t_map *map)
{
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
		perror("Error\nThe map is no closed by '1'.\n");
	else if (type == IMAGE_ERROR)
		perror("Error.\nThe image is not xpm.\n");
	free_map(map);
	exit(-1);
}