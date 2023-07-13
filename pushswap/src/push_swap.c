/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:53:28 by aroca-pa          #+#    #+#             */
/*   Updated: 2023/04/08 05:18:23 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../push_swap.h"
#include <unistd.h>

t_list *startstack(int argc, char **argv)
{
    t_list  *stack_A;
    char    **argt;
    size_t  i;
    size_t  j;

    stack_A = NULL;
    argt = NULL;
    i = 1;
    while ((int)i < argc)
    {
        argt = ft_split(argv[i], ' ');
        if (checkerror(argt) != 0) // llamar a checkerror en argt
        {
            // si hay un error, liberar memoria y salir
            free(argt);
            return NULL;
        }
        j = 0;
        while(argt[j])
        {
            ft_lstadd_back(&stack_A, ft_lstnew((void *)(intptr_t)ft_atoi(argt[j])));
            j++;
        }
        free(argt);
        i++;
    }
    return (stack_A);
}
