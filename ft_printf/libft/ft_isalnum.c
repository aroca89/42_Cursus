/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 09:22:37 by aroca-pa          #+#    #+#             */
/*   Updated: 2022/09/04 12:27:57 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h> //printf
#include "libft.h" /*se inclulle entre " " por qe es una libreria
					personalizada y no una std < > */

int	ft_isalnum(int c)
{
	if ((ft_isalpha(c) || ft_isdigit(c)) == 1)
		return (1);
	return (0);
}

/*int main(void)
{
	char	n;

	n = 'A';
	printf("%d", ft_isalnum(n));
	return (0);
}*/
