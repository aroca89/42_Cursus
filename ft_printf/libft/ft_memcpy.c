/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:39:00 by aroca-pa          #+#    #+#             */
/*   Updated: 2022/09/21 20:38:08 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include<stdio.h>
//#include<string.h>
#include<stdlib.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{	
	if (!dst && !src)
		return (dst);
	while (n > 0)
	{
		n--;
		((char *)dst)[n] = ((const char *)src)[n];
	}
	return (dst);
}

/*int main(void)
{
	size_t n = 6;
	char *memcopy;
	const char src[22] = "hola. chanchito f3liz";
	char dst[22];

	memcopy = memcpy(dst, src, n);
	printf("mia:%s\n", memcopy);
	printf("original:%s\n", memcpy(dst, src, strlen(src)+1));

	return (0);
}*/
