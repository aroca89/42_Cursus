/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:03:15 by aroca-pa          #+#    #+#             */
/*   Updated: 2023/03/19 14:27:45 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

static char	*get_line(char **ptr)
{
	size_t	i;
	char	*str;
	char	*temp;

	i = 0;
	while (*ptr && (*ptr)[i] && (*ptr)[i] != '\n')
		i++;
	str = ft_substr(*ptr, 0, i + 1);
	temp = *ptr;
	*ptr = ft_substr(*ptr, i + 1, ft_strlen(*ptr) - i);
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
	char			*line;
	int				read_ssize;

	while (1)
	{
		if (ft_checkchar(save, '\n'))
			break ;
		line = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!line)
			return (0);
		read_ssize = read(fd, line, BUFFER_SIZE);
		if (read_ssize <= 0)
		{
			free(line);
			if (read_ssize == 0)
				break ;
			free(save);
			save = NULL;
			return (NULL);
		}
		line[read_ssize] = '\0';
		save = ft_strjoin(save, line);
	}
	return (get_line(&save));
}
