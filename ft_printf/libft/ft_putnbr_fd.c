/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 09:39:54 by aroca-pa          #+#    #+#             */
/*   Updated: 2022/12/02 13:43:39 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int ft_putnbr_base_fd(long int n, char *base, int fd)	
{
	int ibase;
	int count;

	count = 0;
	ibase = ft_strlen(base);
	if (n == -2147483648)
		return (ft_putstr_fd("-2147483648", fd));
	if (n < 0 && ibase == 10)   
	{
		n = -n;
		count += ft_putchar_fd('-', fd);
	}
	if (n >= ibase)
		count += ft_putnbr_base_fd((n / ibase), base, fd);
	count += write(fd, &base[(n % ibase)], 1);
	return (count);
}
/*int main()
{
	ft_putnbr_base_fd(-15, "0123456789", 1);
	return (0);
}*/

