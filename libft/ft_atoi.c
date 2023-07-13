/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 14:47:28 by aroca-pa          #+#    #+#             */
/*   Updated: 2022/09/20 17:37:19 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include<stdio.h>
//#include<string.h>
#include<stdlib.h>

static int	isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		dest;
	size_t	i;
	int		plus;

	dest = 0;
	plus = 1;
	i = 0;
	while (isspace(str[i]))
			i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			plus = plus * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		dest = dest * 10 + str[i] - '0';
		i++;
	}
	return (dest * plus);
}

/*int main () 
{
   int val;
   char str[] = "98993489";

   printf("mi funcion:%d\n", ft_atoi(str));

	// funcion original:
   val = atoi(str);
   printf("String value = %s, Int value = %d\n", str, val);

   return(0);
}*/
