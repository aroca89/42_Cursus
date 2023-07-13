/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:47:25 by aroca-pa          #+#    #+#             */
/*   Updated: 2023/03/18 10:48:50 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

size_t	ft_strlen(char *s)
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

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
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
char	*ft_strdup(char *s1)
{
	size_t i;
	char	*str;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
int ft_strchr(char *s, int c)
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
char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	total;
	size_t	len;
	char	*str;

	if (!s1)
		return (s2);
	total = ft_strlen(s1) + ft_strlen(s2);
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
	{
		str[len] = s2[i];
		len++;
		i++;
	}
	free(s1);
	free(s2);
	str[len] = '\0';
	return (str);
}
