/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 04:29:58 by aroca-pa          #+#    #+#             */
/*   Updated: 2023/12/06 19:35:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "../push_swap.h"

int	main(int argc, char *argv[])
{
	if (argc >= 2) {
		t_list	*stack_A;

		stack_A = startstack(argc, argv);
		if	(stack_A == NULL || !check_duplicate(stack_A)) {
			write(2, "ERROR\n", 6);
			free(stack_A);
			return 0;
		}
		if (ft_lstsize(stack_A) <= 3)
			onetwothree(&stack_A);
		else if (ft_lstsize(stack_A) <= 5)
			four_or_five(&stack_A);
		else
			magic_swap(&stack_A);
		free(stack_A);
	}
	return (0);
}
