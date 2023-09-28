/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 04:29:58 by aroca-pa          #+#    #+#             */
/*   Updated: 2023/04/08 05:04:08 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../push_swap.h"
#include <unistd.h>

static void print_list(t_list *list)
{
    while (list)
    {
        printf("%d ", (int)(intptr_t)list->content);
        list = list->next;
    }
    printf("\n");
}

int	main(int argc, char *argv[])
{
	t_list	*stack_A;

	stack_A = startstack(argc, argv);
	if	(stack_A == NULL)
		write(1, "\033[31mERROR\033[0m\n", 15);
	printf("Lista creada: ");
	print_list(stack_A);
	if (ft_lstsize(stack_A) < 4)
		onetwothree(&stack_A);
	if (ft_lstsize(stack_A) > 3)
	{
	//	magic_swap(&stack_A);
	}
	printf("Lista ordenada: ");
	print_list(stack_A);
	

	return (0);
}
