/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 09:31:52 by aroca-pa          #+#    #+#             */
/*   Updated: 2022/09/23 18:00:42 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdlib.h>

static int	ft_cuts(char const *str, char c)
{
	size_t	cuts;
	size_t	i;

	cuts = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			while (str[i] && str[i] != c)
				i++;
			cuts++;
			continue ;
		}
		i++;
	}
	return (cuts);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	i;
	size_t	start;
	size_t	indice;

	str = (char **)malloc(sizeof(char *) * (ft_cuts(s, c) + 1));
	if (!str)
		return (NULL);
	i = 0;
	indice = 0;
	start = 0;
	while (s[i])
	{
		start = i;
		if (s[i] != c)
		{
			while (s[i] && s[i] != c)
				i++;
			str[indice] = ft_substr(s, start, i - start);
			indice++;
			continue ;
		}
		i++;
	}
	return (str[indice] = NULL, str);
}
