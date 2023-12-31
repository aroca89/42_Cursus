/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 04:29:58 by aroca-pa          #+#    #+#             */
/*   Updated: 2023/12/09 13:31:32 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "../push_swap.h"

void print_list(t_list *list)
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
	if (argc >= 2) {
		t_list	*stack_A;

		stack_A = startstack(argc, argv);
		if	(stack_A == NULL || !check_duplicate(stack_A)) {
			write(1, "\033[31mERROR\033[0m\n", 15);
			free(stack_A);
			return 0;
		}
		printf("Lista creada: ");
		print_list(stack_A);
		if (ft_lstsize(stack_A) <= 3)
			onetwothree(&stack_A);
		else if (ft_lstsize(stack_A) <= 5)
			four_or_five(&stack_A);
		else
			magic_swap(&stack_A);
		printf("Lista ordenada: ");
		print_list(stack_A);
		free(stack_A);
	}
	return (0);
}
