/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 13:48:29 by aroca-pa          #+#    #+#             */
/*   Updated: 2022/09/23 17:34:30 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include"libft.h"

static int	ft_intlen(int n)
{
	size_t	len;

	len = 0;
	if (n < 0)
	{
		n = n * (-1);
		len++;
	}
	while (n > 9)
	{
		len++;
		n = n / 10;
	}
	if (n > 0 && n <= 9)
		len++;
	return (len);
}

static int	ft_specific_cases(int n, char **str, size_t *len)
{
	if (n == 0)
	{
		*str = ft_strdup("0");
		return (1);
	}
	if (n == -2147483648)
	{	
		*str = ft_strdup("-2147483648");
		return (1);
	}
	*len = ft_intlen(n);
	*str = (char *)malloc(sizeof(char) * (*len + 1));
	if (!*str)
		return (1);
	return (0);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	sign;
	size_t	len;

	if (ft_specific_cases(n, &str, &len) == 1)
		return (str);
	str[len] = '\0';
	sign = 0;
	if (n < 0)
	{
		n = n * (-1);
		sign = 1;
	}
	while (n > 9)
	{
		str[--len] = (n % 10) + '0';
		n = n / 10;
	}
	if (n > 0 && n <= 9)
		str[--len] = n + '0';
	if (sign == 1)
		str[--len] = '-';
	return (str);
}
