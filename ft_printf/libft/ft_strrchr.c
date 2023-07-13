/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 10:27:45 by aroca-pa          #+#    #+#             */
/*   Updated: 2022/09/14 15:42:51 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include<stdio.h>
//#include<string.h>
#include"libft.h"
#include<stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t	max_len;

	max_len = ft_strlen(s) + 1;
	while (max_len--)
	{
		if (((char *)s)[max_len] == (char)c)
			return ((char *)&s[max_len]);
	}
	return (NULL);
}

/*int main(void)
{
	const char ej_s[] = "hola. mundo f4liz";
	const char ch = 'm';
	char *ret;

	printf("%s\n", ft_strrchr(ej_s, ch));

	//funcion original
	ret = strrchr(ej_s, ch);

	printf("String after |%c| is - |%s|\n", ch, ret);
}*/
