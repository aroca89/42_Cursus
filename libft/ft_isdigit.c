/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 13:51:52 by aroca-pa          #+#    #+#             */
/*   Updated: 2022/12/11 14:26:25 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Esta función verificará si el int entrante es un número */

//#include<ctype.h> //Librería de función original isdigit()
//#include<stdio.h> //Librería de printf

int	ft_isdigit(int c)
{
	return((c >= '0' && c <= '9'));
}

/*cuando se ejecuta la expresión directamente en el return obtenemos que si se cumple devuelve un 1 y de lo contrario si no hay 0*/

/*int main()
{
	int i = 0;
	char cadena[] = "0b2g678bdfk.))¿?";

	while (cadena[i])
	{
		printf("original:%c, %d\t", cadena[i], isdigit(cadena[i]));
		printf("mi funcion:%c, %d\n", cadena[i], ft_isdigit(cadena[i]));
		i++;
	}
	return (0);
}*/
