/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerror.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 04:31:31 by aroca-pa          #+#    #+#             */
/*   Updated: 2023/04/08 05:15:09 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../push_swap.h"
#include <limits.h>
#include <stddef.h>
#include <unistd.h>

int	checkerror(char **argv)
{
    size_t  i;

    i = 0;
    while (*argv != NULL)
    {
        while (argv[0][i] != '\0')
        {
            if (argv[0][i] == '-' || argv[0][i] == '+')
                i++;
            if ((argv[0][i] == '-' || argv[0][i] == '+') ||     \
                    !ft_isdigit(argv[0][i]))
                return (1);
            i++;
        }
        i = 0;
        argv++;
    }
    return (0);
}

void	ft_isint(int nbr)
{
	if (nbr < INT_MIN || nbr > INT_MAX)
		write(1, "\033[31mERROR\033[0m\n", 15);
	return ;
}

void ft_duplicate(t_list **lst)
{
	if ((*lst)->content == (*lst)->next->content
		write(1, "\033[31mERROR\033[0m\n", 15);
	return ;
}
