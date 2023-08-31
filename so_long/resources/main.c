/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 11:24:48 by aroca-pa          #+#    #+#             */
/*   Updated: 2023/08/30 20:43:47 by aroca-pa         ###   ########.fr       */
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
        printf("\n");
        print_map(map);
        printf("\n");
        t_map *map_copy = copy_map(map);
        ft_floodfill(map_copy, map_copy->character_position_col, map_copy->character_position_row);
        
        printf("\n");
        print_map(map_copy);
        printf("\n");
        print_map(map);
        free_map(map);
        
        return EXIT_SUCCESS; // Terminar con éxito;
    }
    else
    {
        perror("Error uso: %s <nombre_del_archivo>\n");
        return (EXIT_FAILURE); // Terminar con un código de error
    }
    
    return (EXIT_SUCCESS); // Terminar con éxito;
}
