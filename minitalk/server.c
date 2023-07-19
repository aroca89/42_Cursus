/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:45:32 by aroca-pa          #+#    #+#             */
/*   Updated: 2023/07/19 21:43:57 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> //
#include "ft_printf.h" // Para ft_printf
#include "unistd.h" // Para getpid()

int ft_signal(int s)
{
	static char c = 0;
	int	i;

	i = 0;

	if (s == SIGUSR1)
	{

	}
	else

	
}

int main(void)
{
	signal(SIGUSR1, ft_signal);
	signal(SIGUSR2, ft_signal);

	ft_printf("Mi PID es: %d\n",getpid());
	while (1)
	{
	 pause ();

	}

	return 0;
}