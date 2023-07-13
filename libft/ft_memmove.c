/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 07:32:07 by aroca-pa          #+#    #+#             */
/*   Updated: 2022/09/16 12:09:04 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (dst < src)
	{
		while (i < len)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i++;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}

/*int main(void)
{
	char s[] = "Hola.";
	const char src[] = "Chancito f3liz";
	size_t len = 3;
	char *fun1;

	fun1 = ft_memmove(s, src, len);
	printf("mi funcion:%s\n", fun1);
	printf("original:%s\n", memmove(s, src, len));
	return (0);
}*/
