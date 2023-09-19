/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 10:19:23 by aroca-pa          #+#    #+#             */
/*   Updated: 2022/09/17 09:33:33 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != '\0')
	{
		j = 0;
		while (haystack[i + j] == needle[j] && (i + j) < len)
		{
			if (needle[++j] == '\0')
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
