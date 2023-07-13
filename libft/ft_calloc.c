/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:40:28 by aroca-pa          #+#    #+#             */
/*   Updated: 2022/09/21 20:57:12 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include<stdlib.h>
//#include<string.h>
//#include<stdio.h>
#include"libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;

	str = (char *)malloc(size * count);
	if (!str)
		return (NULL);
	ft_memset(str, 0, size * count);
	return (str);
}

/*int main(void)
{
	
	printf("final:%s\n", ft_calloc(4, 2));
	printf("orign:%s\n", calloc(4, 2));
	return (0); 
}*/
