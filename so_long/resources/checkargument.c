/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkargument.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 09:56:31 by aroca-pa          #+#    #+#             */
/*   Updated: 2023/08/31 19:05:43 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_42/libft.h" // Inclusión de la biblioteca personalizada libft
#include "../so_long.h"
#include <fcntl.h> // Necesario para la funcion open
#include <unistd.h> // Incluimos unistd.h para la función close

void check_argument(char *argv[])
{
    char *extension;
    size_t extension_len;
    size_t filaname_len;
    
    // Definir la extensión esperada y obtener sus longitudes
    extension = ".ber";
    extension_len = ft_strlen(extension);
    filaname_len = ft_strlen(argv[1]);

    // Verificar si la extensión coincide con la extensión esperada
    if (extension_len > filaname_len || ft_strncmp(argv[1] + filaname_len - extension_len, extension, extension_len) != 0)
        ft_lst_perror(INVALID_EXTENSION, NULL);
    
    // Abrir el archivo en modo de solo lectura
    int archivo;
    archivo = open(argv[1], O_RDONLY);
    
    // Verificar si el archivo se abrió correctamente
    if (archivo == -1)
        ft_lst_perror(INVALID_FILE, NULL);
    
    // Cerrar el archivo después de verificarlo
    close(archivo);
}
