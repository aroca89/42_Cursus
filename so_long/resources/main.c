/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 11:24:48 by aroca-pa          #+#    #+#             */
/*   Updated: 2023/08/22 22:50:21 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        check_argument(argc, argv);
        char **map;
        
        map = convert_map(argv[2]);
        check_map(map);
    }
    else
        perror("Error uso: %s <nombre_del_archivo>\n");
    return 0;
}
