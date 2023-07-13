/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 08:35:11 by aroca-pa          #+#    #+#             */
/*   Updated: 2022/09/08 20:34:35 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include<stdio.h>
//#include<string.h>
#include<stdlib.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	count;

	count = 0;
	while (count < n)
	{
		((char *)s)[count] = c;
		count++;
	}
	return (s);
}

/*int main(void)
{
	char ej_char[] = "hola. Mundo f3liz";
	int ej = '$';
	size_t n = 5;

	printf("%s", (char *)ft_memset(ej_char, ej, n));

return (0);
}*/
