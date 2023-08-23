/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkargument.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 09:56:31 by aroca-pa          #+#    #+#             */
/*   Updated: 2023/08/23 20:56:58 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h" // Necesaria para evitar repeticion de strlen
#include "../ft_printf/ft_printf.h" // Inclusión de la biblioteca personalizada ft_printf
#include "../libft_42/libft.h" // Inclusión de la biblioteca personalizada libft
#include <stdio.h> // Biblioteca estándar para funciones de entrada/salida
#include <stdlib.h> // Biblioteca estándar para funciones de utilidad estándar
#include <string.h> // Biblioteca estándar para manipulación de cadenas
#include <errno.h> // Biblioteca estándar para manejo de errores
#include <fcntl.h> // Necesario para la funcion open
#include <unistd.h> // Incluimos unistd.h para la función close

void check_argument(char *argv[])
{
    char *extension;
    size_t extension_len;
    size_t filaname_len;
    
    extension = ".ber";
    extension_len = ft_strlen(extension);
    filaname_len= ft_strlen(argv[1]);

    if (extension_len > filaname_len || ft_strncmp(argv[1] + filaname_len - extension_len, extension, extension_len) != 0)
    {
        perror("Error: La extension del archivo debe ser '.ber'\n");
        return;
    }
    int archivo;

    archivo = open(argv[1], O_RDONLY);
    if (archivo == -1)
    {
        perror("Error al abrir el archivo\n");
        return;
    }
    close(archivo); // Cierra el archivo cuando ya no es necesario
}