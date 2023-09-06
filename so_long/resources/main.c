/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 11:24:48 by aroca-pa          #+#    #+#             */
/*   Updated: 2023/09/05 22:02:51 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../libft_42/libft.h"
#include <stdlib.h> // Para EXIT_FAILURE y EXIT_SUCCESS

#include  "../minilibx_opengl/mlx.h"

//Inicializa la structura de manera local
static t_map	*ft_init_struct(void)
{
    t_map  *map = (t_map*)calloc(1, sizeof(t_map));
	        if (!map)
		        ft_lst_perror(MALLOC_ERROR, NULL);
	map->render = (t_render*)calloc(1, sizeof(t_render));
	if (!map->render)
		ft_lst_perror(MALLOC_ERROR, map);
	map->img = (t_img *)calloc(1, sizeof(t_img));
	if (!map->img)
		ft_lst_perror(MALLOC_ERROR, map);
	// map->data = NULL;
	// map->cols= 0;
	// map->rows = 0;
	// map->place_start = 0;
	// map->collectibles = 0;
	// map->exit = 0;
	// map->character_position_row = 0;
    // map->character_position_col = 0;
	 map->render->resolution = 64;
     return map;
 }

int main(int argc, char *argv[])
{
    if (argc == 2)
    {  
        check_argument(argv);
        t_map *map = ft_init_struct();
        convert_maps(argv[1], map);
        map_is_rectangular(map); 
        map_closed(map);
        check_points(map);
        t_map *map_copy = copy_map(map);
        ft_floodfill(map_copy, map_copy->character_position_col, map_copy->character_position_row);
        if(is_map_passable(map_copy) == 1)
        {
            printf("%s", "EL MAPA ES PASABLE\n");
            free_map(map_copy);
        }  
        window_init(map);
    
       
        return EXIT_SUCCESS; // Terminar con éxito;
    }
    else
        ft_lst_perror(INVALID_ARGUMENTS, NULL);
    
    return (EXIT_SUCCESS); // Terminar con éxito;
}
