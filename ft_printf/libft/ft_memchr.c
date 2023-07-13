/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 12:06:27 by aroca-pa          #+#    #+#             */
/*   Updated: 2022/09/18 09:48:49 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include<stdio.h>
#include<stdlib.h>
//#include<string.h>
//#include"libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)&s[i]);
		i++;
	}
	return (NULL);
}

/*int main(void)
{
	const void str[] = "hola. Chanchito F3liz ";
	int	c = 'c';
	size_t n = 12;
	char * fun1;

	fun1 = ft_memchr(str, c, n);
	
	printf("mi funcion:%s\n",fun1);
	printf("original:%s\n", memchr(str, c, n))
return (0); 
}*/
