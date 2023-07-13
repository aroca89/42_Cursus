/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:31:12 by aroca-pa          #+#    #+#             */
/*   Updated: 2022/12/05 17:25:13 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdlib.h>
#include"libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	count;

	count = ft_strlen(src);
	if (!dstsize)
		return (count);
	i = -1;
	while (src[++i] && i < dstsize - 1)
		dst[i] = src[i];
	dst[i] = '\0';
	return (count);
}

int main(void)
{
	char dst[500];
	const char src[] = "chanchito feliz";
	printf("%zu\n", ft_strlcpy(dst, src, 5));
	printf("%s\n", dst); 

	return(0);
}
