/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:31:36 by aroca-pa          #+#    #+#             */
/*   Updated: 2023/07/26 19:39:24 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_42/libft.h" // Libreria para nuestras funciones
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

static void ft_send_bit(int server_pid, unsigned char c)
{
    unsigned int bit;

    bit = 0;
    while (bit < 8)
    {
        if (c & (0x01 << bit))
            while (kill(server_pid, SIGUSR1) != 0);
        else
            while (kill(server_pid, SIGUSR2) != 0);
        usleep(50);
        usleep(50);
        bit++; 
    }
}

int main(int argc, char** argv)
{
    if(argc != 2)
    {
        write(1, "\033[31mERROR\033[0m\n", 15);
        return 1;
    }
    
    int server_pid;

    server_pid = ft_atoi(argv[1]);
    ft_send_bit(server_pid, argv[2][0]);

    return 0;
}