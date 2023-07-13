/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:21:27 by aroca-pa          #+#    #+#             */
/*   Updated: 2022/09/21 19:24:17 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include<stdio.h>
#include<stdlib.h>
//#include<string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (n > i)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}

/*int main(void)
{
	const char ej_s1[] = "hola. chanchito";
	const char ej_s2[] = "hoal";
	size_t n = 3;

	printf("mi funcion:%d\n", ft_memcmp(ej_s1, ej_s2, n));

	printf("original:%d\n", memcmp(ej_s1, ej_s2, n));
return (0);
}*/
