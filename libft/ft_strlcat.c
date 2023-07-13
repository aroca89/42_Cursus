/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 10:03:17 by aroca-pa          #+#    #+#             */
/*   Updated: 2022/09/12 20:51:34 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include<stdio.h>
//#include<stdlib.h>
#include "libft.h"

/*esta funcion devuelve el tamaño maximo de la suma de las dos cadenas string*/
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	count;

	count = ft_strlen(dst) + ft_strlen(src);
	if (ft_strlen(dst) >= dstsize)
		return (ft_strlen(src) + dstsize);
	i = 0;
	while (dst[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (count);
}

/*int main (void)
{
	char ej_dest[] = "hola ";
	const char ej_src[] = "mundo";
	printf("%zu\n", ft_strlcat(ej_dest, ej_src, 10));

	return (0);
}*/
