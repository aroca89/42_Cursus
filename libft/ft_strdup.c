/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:07:58 by aroca-pa          #+#    #+#             */
/*   Updated: 2022/09/21 21:01:16 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include<stdio.h>
#include"libft.h"
//#include<string.h>

char	*ft_strdup(const char *s1)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, ft_strlen(s1) + 1);
	return (str);
}

/*int main(void)
{
	const char *ej_s = "hola. chanchito f3liz";
	char *ftstrdup;

	ftstrdup = ft_strdup(ej_s);
	printf("mi funcion:%s\n", ftstrdup);
	
	return (0);
}*/
