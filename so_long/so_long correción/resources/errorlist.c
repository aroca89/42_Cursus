/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorlist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:22:36 by aroca-pa          #+#    #+#             */
/*   Updated: 2023/09/14 12:23:31 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdlib.h>

void	ft_lst_perror(int type, t_map *map)
{
	if (type == 1)
		perror("Wrong number of arguments.\n");
	else if (type == INVALID_FILE)
		perror("Error\nNo such file or directory\n");
	else if (type == INVALID_MAP)
		perror("Error\nInvalid map.Make sure the map is rectangle and is formed \
only by: '0', '1', 'E', 'P' and 'C'\n");
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
	else if (type == PLAYER_CANNOT_REACH_EXIT)
		perror("Error.\nAn inaccessible cell was found\n");
	free_map(map);
	exit(-1);
}

void	ft_mlx_perror(int type, t_map *map)
{
	if (type == 1)
		perror("Error\nMinilibx not found\n");
	else if (type == 2)
		perror("Error\nwindow not found\n");
	else if (type == 3)
		perror("Error\nSprite not load\n");
	else if (type == 4)
		perror("Error\nLoading background texture\n");
	else if (type == 5)
		perror("Error\nloading collectible textures.\n");
	else if (type == 6)
		perror("Error\nloading the exit texture.\n");
	else if (type == 7)
		perror("Error\nloading player texture.\n");
	else if (type == 8)
		perror("Error\nloading the walls texture.\n");
	free_map(map);
	exit(-1);
}

void	free_map(t_map *map)
{
	int		i;

	if (map != NULL)
	{
		i = 0;
		while (map->data[i] != NULL)
		{
			free(map->data[i]);
			i++;
		}
		free(map->data);
		free(map);
	}
}
