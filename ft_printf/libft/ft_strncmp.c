/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 09:58:18 by aroca-pa          #+#    #+#             */
/*   Updated: 2022/09/12 11:56:23 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include<stdio.h>
#include<stdlib.h>
//#include<string.h>
//#include"libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = -1;
	while (++i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}

/*int main(void)
{
	int fun1;
	const char ej_s = "";
	const char ej_ss = "";
	size_t n = 5;

	fun1 = strncmp( ej_s, ej_ss, n);
	printf("mi funcion:%s\n", fun1);
	printf("original:%s\n", strncmp("hola", "hola paco" ) );
	
	return (0);
}*/
