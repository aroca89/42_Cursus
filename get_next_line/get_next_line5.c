/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:03:15 by aroca-pa          #+#    #+#             */
/*   Updated: 2023/03/10 08:26:21 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

static char	*NewRead(int fd, char *save)
{
	char	*str;
	ssize_t read_ssize;
	
	read_ssize = 1;
	while (read_ssize > 0)
	{
		str = (char *)malloc(sizeof(char) * ( BUFFER_SIZE + 1));
		read_ssize = read(fd, str, BUFFER_SIZE);
		if (read_ssize == -1)
			return (0);
		if (read_ssize == 0)
			break ;
		if (!save)
			save = ft_strdup("hola");
	//	printf("strdup>>>>%s\n", save);
		str[read_ssize] = '\0';
		save = ft_strjoin(save, str);
		if (ft_strchr(save, '\n'))
			break ;
	}
	return (save);
}

static char	*GetLine(char *ptr)
{
	size_t	i;
	char	*str;

	i = 0;
	while (ptr[i] && ptr[i] != '\n')
		i++;
	if (ptr[i] == '\0')
		return (0);
	str = ft_substr(ptr, i + 1, ft_strlen(ptr) - i);
	//str = ft_substr(ptr, 0, i);
	if (*str == '\0')
	{
		free (str);
		str = NULL;
	}
	ptr[i + 1] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static char		*save;
	char		*line;
	
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	//line = (char *)malloc(sizeof(char) * (BUFFER_SIZE));
//	if (!line)
//		return (0);
	save = NewRead(fd, save);
	printf("line>>>>%s\n", save);
	if (!save)
	{
		free (save);
		save = NULL;
		return (NULL);
	}
	line = GetLine(save);
	return (line);
}
