/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:31:36 by aroca-pa          #+#    #+#             */
/*   Updated: 2023/09/25 17:47:06 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_42/libft.h" // Libreria para nuestras funciones
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

static void	ft_send_bit(int server_pid, unsigned char c)
{
	unsigned int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (0x01 << bit))
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(50);
		usleep(50);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	server_pid;
	int	i;

	i = 0; 
	if (argc != 3)
	{
		write(1, "\033[31mERROR\033[0m\n", 15);
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		ft_send_bit(server_pid, argv[2][0]);
		i++;
	}
	return (0);
}