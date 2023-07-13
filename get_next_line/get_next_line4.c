/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:03:15 by aroca-pa          #+#    #+#             */
/*   Updated: 2023/03/10 08:20:25 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

static char *ft_NewRead(int fd)
{
	char *str;
	int *buffer

	str = (char *)malloc(BUFFER_SIZE * (sizeof(char) + 1)	);
	if (!str)
		return (0);
	buffer = read(fd, str, BUFFER_SIZE);
	str[buffer] = '\0';
	printf("lectura:%s\t\tarchive=%d\n", str, *buffer);
	return (str);
}

static char *ft_getline(int fd, int buffer, char **ptr)
{
	int i;
	char *str;
	
	str = NULL;
	i = ft_strchr(*ptr, '\n');
	if(i != -1)
	{
		str = ft_substr(*ptr, 0, i + 1);
		printf("<STR ft_getline>>>:::%s\n\n", str);
		*ptr = &(*ptr)[i + 1];
		printf("<PTR ft_getline>:%s\n",*ptr);
	}
	else
	{
		if (&buffer <= 0)
			return (str);
		*ptr = ft_strjoin(*ptr, ft_NewRead(fd, buffer));
		*ptr = ft_getline(fd, buffer, ptr);
	
	}
	return(str);
}
char	*get_next_line(int fd)
{

	static char *resto;
	int buffer;
	printf("guardado:%s\n\n", resto);
	char *line;

	line = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (!resto)
		resto = ft_NewRead(fd);
	if (resto && resto != 0)
	{
		if(ft_strlen(resto) == 0)
			resto = ft_NewRead(fd, buffer);
		line = ft_getline(fd, &resto);

	}


	return (line);
}


