/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 11:24:48 by aroca-pa          #+#    #+#             */
/*   Updated: 2023/08/24 18:08:22 by aroca-pa         ###   ########.fr       */
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
        print_map(map);
        map_is_rectangular(map); 
        map_closed(map); 
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
