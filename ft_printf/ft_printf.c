/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 06:10:09 by aroca-pa          #+#    #+#             */
/*   Updated: 2022/11/27 11:56:16 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(char const *str, ...)
{

	t_printf	valor;
	va_start (valor.arg, str);

	valor.str = str;
	valor.i = 0;
	valor.len = 0;
	
	while (str[valor.i])
	{
		if (str[valor.i] == '%')
		{
			valor.i += 1;
			ft_checkflags (&valor);
		}
		else
		{
			ft_putchar_fd(str[valor.i], 1);
			valor.len++;
		
		}
		valor.i++;
	}
	va_end(valor.arg);
	return (valor.len);
}
