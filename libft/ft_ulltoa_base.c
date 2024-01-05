/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:57:42 by aroca-pa          #+#    #+#             */
/*   Updated: 2024/01/05 12:56:08 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_ulltoa_base(unsigned long long n, int base)
{
	int					len;
	char				*result;
	char				*lookup;
	unsigned long long	tmp;

	tmp = n;
	len = 0;
	lookup = "0123456789abcdefghijklmnopqrstuvwxyz";
	while (tmp != 0)
	{
		tmp /= (unsigned long)base;
		++len;
	}
	result = (char *)malloc(sizeof(char) * (len + 2));
	if (!result)
		return (NULL);
	result[len + 1] = '\0';
	while (len >= 0)
	{
		result[len] = lookup[n % base];
		n /= base;
		len--;
	}
	return (result);
}
