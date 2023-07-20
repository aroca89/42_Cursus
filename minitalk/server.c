/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:45:32 by aroca-pa          #+#    #+#             */
/*   Updated: 2023/07/20 21:23:09 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> //
#include "../libft/libft.h" // Libreria para nuestras funciones
#include "unistd.h" // Para getpid()

void ft_signal_received(int sig)
{
	int	bit; 
	unsigned char received_data;

	bit	= 0;
	received_data = 0;
	while (bit < 8)
	{
		if (sig == SIGUSR1) //Establece el bit en la posición 'bit' como 1
		{
			received_data |= (0x01 << bit);
		}
		else if (sig == SIGUSR2) // El bit en la posición 'bit' ya es 0, no es necesario hacer nada
			// Podemos añadir coigo aqui para manejar la señal SIGUSR2 si seria necesario 
		bit++;
	}
	ft_putchar_fd(received_data, 1);
}

int main(void)
{
	signal(SIGUSR1, ft_signal_received);
	signal(SIGUSR2, ft_signal_received);

	ft_putstr_fd("Mi PID es:", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	while (1)
		pause ();
	return 0;
}