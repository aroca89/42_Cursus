/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 11:55:06 by aroca-pa          #+#    #+#             */
/*   Updated: 2022/09/21 19:26:49 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include<stdio.h>
#include<stdlib.h>
//#include<string.h>
//#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	count;
	char	*str;

	count = 0;
	str = (char *)s;
	while (count < n)
	{
		str[count] = 0;
		count++;
	}
}

/*int  main (void)
{
	char ej_str[] = "hola. Mundo F3liz";
	size_t p = 6;
	size_t	i = 0;

	ft_bzero(ej_str, p);
	printf("string: %s\n", ej_str + p);//+ P salta lo no printeable
	while (i < 25) // este main imprime char a char
	{
		printf("%c0\n", ej_str[i]); //imprime 0 en cada linea y el resto del str
		i++;
	}

 return (0);
}*/
