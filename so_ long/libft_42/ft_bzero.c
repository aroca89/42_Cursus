/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 11:55:06 by aroca-pa          #+#    #+#             */
/*   Updated: 2022/09/21 19:26:49 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	count;
	char	*str;

	count = 0;
	str = (char *)s;
	while (count < n)
	{
		str[count] = 0;
		count++;
	}
}
