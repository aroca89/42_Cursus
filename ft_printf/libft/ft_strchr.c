/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 08:38:39 by aroca-pa          #+#    #+#             */
/*   Updated: 2022/09/16 09:02:22 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include<stdio.h>
//#include<string.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

/*int main(void)
{
	const char ej_str[] = "hola. mundo f4liz";
	const char ch = '4';
	char *ret;

	printf("mi funcion:%s\n", ft_strchr(ej_str, ch));

	ret = strchr(ej_str, ch);

	printf("String after |%c| is - |%s|\n", ch, ret);
return (0);
}*/
