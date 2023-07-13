/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 12:40:00 by aroca-pa          #+#    #+#             */
/*   Updated: 2022/09/23 18:00:45 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include<stdio.h>
#include<stdlib.h>
#include"libft.h"
//#include<string.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len && s[i] != '\0')
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

/*int main(void)
{
	char *sustr;
	const char *ej_s = "hola. Chanchito F3liz";
	sustr = ft_substr(ej_s, 4, 12);
	printf("mi funcion:%s\n", sustr);
	return (0);
}*/
