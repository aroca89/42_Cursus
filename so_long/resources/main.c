/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 11:24:48 by aroca-pa          #+#    #+#             */
/*   Updated: 2023/09/01 20:17:14 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdlib.h> // Para EXIT_FAILURE y EXIT_SUCCESS


int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        check_argument(argv);
        t_map *map = convert_maps(argv[1]);
        map_is_rectangular(map); 
        map_closed(map);
        check_points(map);
        t_map *map_copy = copy_map(map);
        print_map(map);
        printf("\n");
        
        ft_floodfill(map_copy, map_copy->character_position_col, map_copy->character_position_row);
        
        print_map(map_copy);
        if(is_map_passable(map_copy) == 1)
            printf("%s", "EL MAPA ES PASABLE");
        return EXIT_SUCCESS; // Terminar con éxito;
    }
    else
        ft_lst_perror(INVALID_ARGUMENTS, NULL);
    
    return (EXIT_SUCCESS); // Terminar con éxito;
}
