/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkargument.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 09:56:31 by aroca-pa          #+#    #+#             */
/*   Updated: 2023/09/25 13:07:01 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_42/libft.h"
#include "../so_long.h"
#include <fcntl.h>
#include <unistd.h>

void	check_argument(char *argv[])
{
	char	*extension;
	size_t	extension_len;
	size_t	filaname_len;
	int		archivo;

	extension = ".ber";
	extension_len = ft_strlen(extension);
	filaname_len = ft_strlen(argv[1]);
	if (extension_len > filaname_len || ft_strncmp(argv[1] + filaname_len - \
		extension_len, extension, extension_len) != 0)
		ft_lst_perror(INVALID_EXTENSION, NULL);
	archivo = open(argv[1], O_RDONLY);
	if (archivo == -1 || read(archivo, NULL, 1) == 0)
		ft_lst_perror(INVALID_FILE, NULL);
	close(archivo);
}
