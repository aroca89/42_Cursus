/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:03:15 by aroca-pa          #+#    #+#             */
/*   Updated: 2023/03/19 08:53:19 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"


static char	*GetLine(char **ptr)
{
	size_t	i;
	char	*str;
	char *temp;

	i = 0;
	while (*ptr && (*ptr)[i] && (*ptr)[i] != '\n')
		i++;
//	if ((*ptr)[i] == '\0')
//		return (str);
	str = ft_substr(*ptr, 0, i + 1);
	temp = *ptr;
	*ptr = ft_substr(*ptr, i + 1 , ft_strlen(*ptr) - i -1);
	free(temp);
	if (*str == '\0')
	{
		free (str);
		str = NULL;
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char		*save;
	char		*line;
	int	read_ssize;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	read_ssize = 1;
	while (read_ssize > 0)
	{
		if (ft_strchr(save, '\n'))
			break ;
		line = (char *)malloc((BUFFER_SIZE + 1)* sizeof(char));
		if (!line)
			return(0);
		read_ssize = read(fd, line, BUFFER_SIZE);
		if (read_ssize <= 0)
		{
			free(line);
			break ;
		}
		line[read_ssize] = '\0';
		save = ft_strjoin(save, line);
	}
	if (!save || *save ==  '\0')
	{
		free (save);
		save = NULL;
		return (NULL);
	}
	line = GetLine(&save);
	return (line);
}
