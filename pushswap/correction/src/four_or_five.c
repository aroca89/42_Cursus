#include <stdio.h>
#include <unistd.h>

#include "../push_swap.h"


static void rotate_min_moves(t_list **lst, int index)
{
	int size;

	size = ft_lstsize(*lst);
	if (index <= size / 2)
		rotate_ra(lst);
	else
		rotate_rra(lst);
}

static void find_smaller(t_list **lst)
{
    t_list *temp;
    t_list *smaller;
	int index;
	int index_smoller;

    temp = *lst;
    smaller = temp;
    while (temp)
    {
        if ((int)(intptr_t)smaller->content > (int)(intptr_t)temp->content)
		{
            smaller = temp;
			index_smoller = index;
		}
		temp = temp->next;
		index++;
    }
    while ((*lst)->content != smaller->content)
        rotate_min_moves(lst, index_smoller);
}

static void find_push(t_list **lst, t_list **stack_B)
{
	while (ft_lstsize(*lst) > 3)
	{
		find_smaller(lst);
		push(stack_B, lst, 'a');
	}
}
static void empty_stack(t_list **list_dest, t_list **list_origin)
{
	while (list_origin && ft_lstsize(*list_origin) > 0)
		push(list_dest, list_origin, 'b');
}

void four_or_five(t_list **lst)
{
	t_list *stack_B;

	stack_B = NULL;
	find_push(lst, &stack_B);
	onetwothree(lst);
	empty_stack(lst, &stack_B);
	free(stack_B);
}