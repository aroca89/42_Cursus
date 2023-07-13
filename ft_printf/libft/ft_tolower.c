/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 07:53:55 by aroca-pa          #+#    #+#             */
/*   Updated: 2022/09/04 08:34:44 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include<ctype.h> //lib std tolower
//#include<stdio.h> //lib std printf

/*funcion que convierte en minuscula si se puede, 
	delo contrario devuelve el caracter pasado*/

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

//comprobacion

/*int main(void)
{
	char letra;

	letra = 'c';
	printf("%c", ft_tolower(letra));

//funcion original
//------------------
	printf("Ingrese letra:\n");
    scanf( "%c", &letra );
    letra = tolower( letra );
    printf("\nSu letra es:%c",letra);


	return (0);
}*/
