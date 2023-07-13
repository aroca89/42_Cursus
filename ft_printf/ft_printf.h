/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 19:28:34 by aroca-pa          #+#    #+#             */
/*   Updated: 2022/12/01 13:09:44 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_printf
{	
	size_t	i;
	size_t	len;
	const char	*str;
	va_list arg;
}	t_printf;

int ft_printf(char const *str, ...);
int ft_checkflags(t_printf *valor);

#endif
