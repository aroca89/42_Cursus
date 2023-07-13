/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 13:38:37 by aroca-pa          #+#    #+#             */
/*   Updated: 2022/09/21 20:43:36 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include<stdio.h> 
//#include<ctype.h>

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

/*int main(void)
{
char letra;

letra = 'B';
printf("%c", ft_toupper(letra));

////funcion original\\\\
------------------------
printf("ingrese una letra: a");
scanf("%c", &letra);

letra = toupper(letra);
printf("laletra mayuscula es: %c\n", letra);

return (0);
}*/
