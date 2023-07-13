/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:03:15 by aroca-pa          #+#    #+#             */
/*   Updated: 2023/02/27 20:57:08 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

size_t INDICE;

char	*get_next_line(int fd)
{
	ssize_t archive;
	char *readlen;
	static char *resto;
	char *copy;

	copy = (char *)malloc(sizeof(char));
	copy[0] = '\0';
	//printf("HOLA QE HACE");

	readlen = (char *)malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (!readlen)
		return (0);

	if(resto)
	{
		//printf("resto>>>>>>====%s\n\n", resto);
		INDICE = 0;
		while(resto[INDICE] && resto[INDICE] !='\n')
		{
			INDICE++;
		}
		//printf("resto:%s\tINDICE:%zu\n", resto, INDICE);
		if(resto[INDICE] == '\n')
		{
			copy = ft_substr(resto, 0, INDICE + 1);
		}
		//printf("copy:%s\tINDICE:%zu\n", copy, INDICE);
		resto = &resto[INDICE + 1];
		printf("resto1:%s\tINDICE:%zu\n", resto, INDICE);
		//printf("copyIndice>>>>>=====%c\n\n========", copy[INDICE -3]);
		if(copy[INDICE] == '\n')
			return(copy);
	}


	archive = read(fd, readlen, BUFFER_SIZE);
	readlen[archive] = '\0';
//	printf("readlen:%s%zu\n", readlen, INDICE);
	INDICE = 0;
	if (BUFFER_SIZE <= 0 || archive == -1)
		return ("-1");
	if (archive == 0)
		return (NULL);

	while(readlen[INDICE] && readlen[INDICE] != '\n' && archive > 0)
		INDICE++;
	if(copy)
	{
		INDICE = 0;
		printf("ENTRA EN JOIN%s", copy);
		copy = ft_strjoin( resto, readlen);
		while(copy[INDICE] && copy[INDICE] != '\n')
			{
				INDICE++;

			}
		
		copy = ft_substr(copy, 0, INDICE);
		resto = &resto[INDICE + 1];
	
	}
	else
	{
		copy = ft_substr(readlen, 0, INDICE +1);
		resto = &readlen[INDICE + 1];
		
	}
printf("copy:%s\tINDICE:%zu\tarchive:%zu\n", copy, INDICE, archive);
printf("resto:%s\tINDICE:%zu\n", resto, INDICE);
	free(readlen);
	return (copy);
}
