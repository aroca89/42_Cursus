/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:03:15 by aroca-pa          #+#    #+#             */
/*   Updated: 2023/03/02 12:31:08 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

static char *ft_NewRead(int fd)
{
	ssize_t buffer;
	char *str;

	str = (char *)malloc(BUFFER_SIZE * (sizeof(char) + 1)	);
	if (!str)
		return (0);
	buffer = read(fd, str, BUFFER_SIZE);
	str[buffer] = '\0';
	printf("lectura:%s\t\tarchive=%zu\n", str, buffer);
	return (str);
}
static int Find(char *ptr)
{
	int i;

	i = 0;
	while(ptr[i] != '\n')
	{
		if (ptr[i] == '\0')
			return(-1);
		i++;
	}
	return (i);
}

static char *ft_getline(int fd, char **ptr)
{
	int i;
	char *str;
	
	i = Find(*ptr);
	if((*ptr)[i] == '\n')
	{
		str = ft_substr(*ptr, 0, i + 1);
		printf("<STR ft_getline>>>:::%s\n\n", str);
		*ptr = &(*ptr)[i + 1];
		printf("<PTR ft_getline>:%s\n",*ptr);
		return (str);
	}
	else
	{
		*ptr = ft_strjoin(*ptr, ft_NewRead(fd));
		*ptr = ft_getline(fd, ptr);
	
	}
	return(*ptr);
}
char	*get_next_line(int fd)
{

	static char *resto;
	printf("guardado:%s\n\n", resto);
	int	buffer;
	char *line;

	line = NULL;
	if (BUFFER_SIZE <= 0 || fd == -1)
		return (NULL);
	if (!resto)
		resto = ft_NewRead(fd);

    buffer = ft_strlen(resto);

	if (resto && resto != 0)
	{
	
		if (buffer == 0)
			resto = ft_NewRead(fd);
			printf("fd>>>>:%d\n", buffer);
		line = ft_getline(fd, &resto);

	}


	return (line);
}


