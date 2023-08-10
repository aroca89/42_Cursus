/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 09:18:12 by aroca-pa          #+#    #+#             */
/*   Updated: 2022/12/07 16:27:23 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"

static int	ft_putstrlen(char *s, int bool)
{
	unsigned int	i;

	i = 0;
	if (!s)
		return (write(1, "(null)", 6));
	else
	{
		while (s[i] != '\0')
		{
			if (bool == 1)
				write(1, &s[i], 1);
			i++;
		}
	}
	return (i);
}

static int	ft_address(unsigned long int n, char *base)
{
	size_t	ibase;
	int		len;

	len = 0;
	ibase = ft_putstrlen(base, 0);
	if (n >= ibase)
		len = ft_address((n / ibase), base);
	len += write(1, &base[(n % ibase)], 1);
	return (len);
}

static int	ft_putnbr_base( long int n, char *base)
{
	int	ibase;
	int	len;

	len = 0;
	ibase = ft_putstrlen(base, 0);
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0 && ibase == 10)
	{
		n = -n;
		len += write(1, "-", 1);
	}
	if (n >= ibase)
		len += ft_putnbr_base((n / ibase), base);
	len += write(1, &base[(n % ibase)], 1);
	return (len);
}

static int	ft_checkformat(va_list arg, char const *str, int len, char c)
{
	len = 0;
	if (*str == 'c')
	{
		c = va_arg(arg, int);
		len = write(1, &c, 1);
	}
	else if (*str == 's')
		len = ft_putstrlen(va_arg(arg, char *), 1);
	else if (*str == 'p')
		len = ft_putstrlen("0x", 1) + \
			ft_address(va_arg(arg, unsigned long int), "0123456789abcdef");
	else if (*str == 'd' || *str == 'i')
		len = ft_putnbr_base(va_arg(arg, int), "0123456789");
	else if (*str == 'u')
		len = ft_putnbr_base(va_arg(arg, unsigned int), "0123456789");
	else if (*str == 'x')
		len = ft_putnbr_base(va_arg(arg, unsigned int), "0123456789abcdef");
	else if (*str == 'X')
		len = ft_putnbr_base(va_arg(arg, unsigned int), "0123456789ABCDEF");
	else if (*str == '%')
		len = write(1, "%", 1);
	return (len);
}

int	ft_printf(char const *str, ...)
{
	int		i;
	int		len;
	va_list	arg;
	char	c;

	va_start (arg, str);
	c = '\0';
	i = 0;
	len = 0;
	while (str[i])
	{		
		if (str[i] != '%')
			len += write(1, &str[i], 1);
		else if (str[i] == '%' && str[i + 1] != '\0')
			len += ft_checkformat(arg, &str[++i], len, c);
		i++;
	}
	va_end (arg);
	return (len);
}
