/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:19:32 by aroca-pa          #+#    #+#             */
/*   Updated: 2022/12/02 13:42:49 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"
#include<stdio.h>

static int ft_checkvalor(t_printf *valor)
{
		if (valor->str[valor->i] == 'c')
			valor->len += ft_putchar_fd(va_arg(valor->arg, int), 1);
		else if (valor->str[valor->i]  == 's')
			valor->len += ft_putstr_fd(va_arg(valor->arg, char *), 1);
		else if (valor->str[valor->i]  == 'p')
		{
			valor->len += ft_putstr_fd("0x",1) + ft_putnbr_base_fd(va_arg(valor->arg, unsigned long int), "0123456789abcdef", 1);
		}
		else if (valor->str[valor->i]  == 'd' || valor->str[valor->i] == 'i')
			valor->len +=  ft_putnbr_base_fd(va_arg(valor->arg, int), "0123456789", 1);
		else if (valor->str[valor->i]  == 'u')
           valor->len +=  ft_putnbr_base_fd(va_arg(valor->arg, unsigned int), "0123456789", 1);
		else if (valor->str[valor->i]  == 'x')
			valor->len +=  ft_putnbr_base_fd(va_arg(valor->arg, unsigned int), "0123456789abcdef", 1);
		else if (valor->str[valor->i]  == 'X')
			valor->len +=  ft_putnbr_base_fd(va_arg(valor->arg, unsigned int), "0123456789ABCDEF", 1);
		else if (valor->str[valor->i]  == '%')
            valor->len += ft_putchar_fd('%', 1);
	return(valor->len);
 }

 int ft_checkflags(t_printf *valor)
 {
      return (ft_checkvalor(valor));
      /*size_t i;
 
      i = valor.i;
      valor.cflag = cflag;
      if (s[i] == '-') // si el argumento es negativo no si la flag!!!
      {
 
          if (s[i] == ' ')
              cflag = s[i];
          else if (s[i] == '#')
          {
              i++;
              if (s[i] == 'x')
                  cflag = "0x";
              else if (s[i] == 'X')
                  cflag = "0X";
          }
      }
      i++;
 
      return (len);*/
 }
