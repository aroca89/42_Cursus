/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerror.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 04:31:31 by aroca-pa          #+#    #+#             */
/*   Updated: 2023/12/02 17:18:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../push_swap.h"
#include <limits.h>
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>


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
		write(1, "ERROR\n", 15);
	return ;
}

int check_duplicate(t_list *lst)
{
    t_list *current;
    t_list *check;

    if (!lst || !(lst->next))
        return 0;
    check = lst;
    while(check != NULL)
    {
        current = check->next;
        while(current != NULL)
        {
            if ((int)(intptr_t)check->content == (int)(intptr_t)current->content)
                return 0;
            current = current->next;
        }
        check = check->next;
    }
    return 1;
}
