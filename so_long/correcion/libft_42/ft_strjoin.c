/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 08:11:21 by aroca-pa          #+#    #+#             */
/*   Updated: 2023/09/19 09:16:05 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include"libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	total;
	size_t	len;
	char	*str;

	if (!s1)
		return ((char *)s2);
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
		str[len++] = s2[i++];
	free((char *)s1);
	free((char *)s2);
	str[len] = '\0';
	return (str);
}
