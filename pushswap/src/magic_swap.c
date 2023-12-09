/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 04:48:58 by aroca-pa          #+#    #+#             */
/*   Updated: 2023/12/09 13:31:19 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <limits.h>

#include "../push_swap.h"

static int get_pivot(t_list *lst)
{
	int min = INT_MAX;
	int max = INT_MIN;
	int pivot;

	while (lst != NULL)
	{
		if (min > (int)(intptr_t)lst->content)
		{
			min = (int)(intptr_t)lst->content;
		}
		if (max < (int)(intptr_t)lst->content)
		{
			max = (int)(intptr_t)lst->content;
		}
		lst = lst->next;
	}
	//printf("El valor más pequeño es: %d\n", min);
	//printf("El valor más grande es: %d\n", max);
	pivot = (min + max) / 2;

	return pivot;
}

static void magic(t_list **list, t_list **stack_B)
{
    int index;
    int size;
	int pivot;

	pivot = get_pivot(*list);
    index = 0;
    size = ft_lstsize(*list);
    while (index < size)
    {
        if ((int)(intptr_t)(*list)->content <= pivot)
        {
			if ((int)(intptr_t)(*list)->content > (int)(intptr_t)(stack_B))
			{
				while ((int)(intptr_t)(*list)->content > (int)(intptr_t)(*stack_B)->content)
				{
    				rotate_ra(stack_B);
    				*list = (*list)->next;  // Avanza al siguiente nodo
				}
			}
            push(stack_B, list, 'b');
        }
        else
            rotate_ra(list);
        index++;
    }
}


void magic_swap(t_list **lst)
{
    t_list *stack_B;
	int diff;

  	stack_B = NULL;
	diff = ft_lstsize(*lst) - ft_lstsize(stack_B);
	while (diff > 1 || diff < -1)
    {
		if(ft_lstsize(*lst) > ft_lstsize(stack_B))
		{
        	magic(lst, &stack_B);
		}
		else
			magic(&stack_B, lst);
        diff = ft_lstsize(*lst) - ft_lstsize(stack_B);
		printf("diff: %d\n", diff);
    }



	printf("stack_B in find_push: ");
    print_list(stack_B);
    printf("stack_A final : ");
    print_list(*lst);
}




	
