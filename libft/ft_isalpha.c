/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 10:25:17 by aroca-pa          #+#    #+#             */
/*   Updated: 2022/12/11 13:42:56 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Con esta función verificamos si estamos obteniendo una int de tipo letra.*/


//#include<ctype.h> // Librería, función original isalpha()
//#include<stdio.h> // Librería, printf

int	ft_isalpha(int c)
{
	return((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ) ;
}

/*cuando se ejecuta la expresión directamente en el return obtenemos que si se cumple devuelve un 1 y de lo contrario si no hay 0*/


/*int main()
{
   char cadena[] = ";0sR(h&R1/";


   while (cadena[i])
   {
	   printf("%c, %d\t", cadena[i], isalpha(cadena[i]));
	   printf("%c, %d\n", cadena[i], ft_isalpha(cadena[i]));
		i++;
   }
   return (0);
}*/
