/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 14:47:28 by aroca-pa          #+#    #+#             */
/*   Updated: 2022/10/05 09:42:45 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


static int checkbase(char c)
{
	if (c >= '0' && c <= '9')
		return (int)c - '0';
	else
		return (int)c - 'A' + 10;
}
int	ft_atoi(const char *str, char *base)
{
	int		dest;
	size_t	i;
	int		sing;
	size_t	ibase;

	dest = 0;
	sing = 1;
	i = 0;
	ibase = strlen(base);
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		sing = -sing;
	i++;
	while (str[i])
	{	
		printf("numero :%.d\n", str[i]);
		dest = (dest * ibase) + checkbase(str[i]);
		printf("numero *:%.d\n", dest);
		i++;
	}
	printf("ibase:%zu\n", ibase);
	return (dest * sing);
}

int main () 
{
   //int val;
   char str[] = "23675";
   char base[] = "0123456789";
   printf("mi funcion:%d\n", ft_atoi(str, base));

	// funcion original:
   //val = atoi(str);
   //printf("String value = %s, Int value = %d\n", str, val);

   return(0);
}
