/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 23:59:51 by aroca-pa          #+#    #+#             */
/*   Updated: 2022/11/29 11:35:19 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<unistd.h>

int	ft_putstr_fd(char *s, int fd)
{
	int len;
	
	len = 0;
	if (s)
	{
		len = ft_strlen(s);
		write(fd, s, len);
		return (len);
	}
		write(fd, "(null)", 6);
		return (6);
}
