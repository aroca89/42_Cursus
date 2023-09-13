/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:47:25 by aroca-pa          #+#    #+#             */
/*   Updated: 2023/08/30 20:39:33 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

size_t	ftgnl_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (s)
	{
		while (s[len] != '\0')
			len++;
	}
	return (len);
}

char	*ftgnl_substr(const char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (ftgnl_strlen(s) < start)
		return (NULL);
	if (ftgnl_strlen(s) < len)
		len = ftgnl_strlen(s);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len && s[i] != '\0' )
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_checkchar(char *s, int c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == (char)c)
			return (1);
		s++;
	}
	return (0);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	total;
	size_t	len;
	char	*str;

	if (!s1)
		return ((char *)s2);
	total = ftgnl_strlen(s1) + ftgnl_strlen(s2);
	str = (char *)malloc(sizeof(char) * total + 1);
	if (!str)
		return (NULL);
	len = 0;
	while (s1 && s1[len])
	{
		str[len] = s1[len];
		len++;
	}
	i = 0;
	while (s2 && s2[i])
		str[len++] = s2[i++];
	free((char *)s1);
	free((char *)s2);
	str[len] = '\0';
	return (str);
}
