/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 10:27:45 by aroca-pa          #+#    #+#             */
/*   Updated: 2022/09/14 15:42:51 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t	max_len;

	max_len = ft_strlen(s) + 1;
	while (max_len--)
	{
		if (((char *)s)[max_len] == (char)c)
			return ((char *)&s[max_len]);
	}
	return (NULL);
}
