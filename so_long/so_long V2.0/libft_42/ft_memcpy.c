/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:39:00 by aroca-pa          #+#    #+#             */
/*   Updated: 2022/09/21 20:38:08 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{	
	if (!dst && !src)
		return (dst);
	while (n > 0)
	{
		n--;
		((char *)dst)[n] = ((const char *)src)[n];
	}
	return (dst);
}
