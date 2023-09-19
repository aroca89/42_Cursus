/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 08:56:38 by aroca-pa          #+#    #+#             */
/*   Updated: 2022/09/20 19:21:26 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include"libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	fin;

	start = 0;
	fin = ft_strlen(s1);
	while (ft_strchr(set, (int)s1[start]))
			start++;
	while (ft_strchr(set, (int)s1[fin]))
		fin--;
	return (ft_substr(s1, start, fin - start + 1));
}
