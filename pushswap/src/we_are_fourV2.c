#include <stdio.h>
#include <unistd.h>

#include "../push_swap.h"

static int calculate_min_moves(t_list *lst, t_list *node)
{
	int forward_steps = 0;
	int backward_steps = 0;
	int total_steps = 0;
	t_list *temp = lst;

	while (temp)
	{
		if (temp == node)
		{
			forward_steps = total_steps;
		}
		temp = temp->next;
		total_steps++;
	}
	backward_steps = total_steps - forward_steps - 1;	
	
	if (forward_steps <= backward_steps)
		return (forward_steps);
	else
		return (backward_steps);
}

static void find_bigger_smoller(t_list *lst)
{
	t_list *temp;
	t_list *bigger;
	t_list *smoller;

	temp = lst;
	bigger = temp;
	smoller = temp;

	while (temp)
	{
		if ((int)(intptr_t)bigger->content < (int)(intptr_t)temp->content)
			bigger = temp;
		if ((int)(intptr_t)smoller->content > (int)(intptr_t)temp->content)
			smoller = temp;
		temp = temp->next;	
	}
	if (calculate_min_moves(lst, bigger) > calculate_min_moves(lst, smoller))
		while ( lst->content != bigger->content)
		{
			rotate_ra(&lst);
		}		
	else
		while( lst->content != smoller->content)
			rotate_rra(&lst);
}


static void find_push(t_list *lst)
{
	t_list *stack_B;

	find_bigger_smoller(lst);
	
	stack_B = NULL;

	push(&stack_B, &lst, 'a');
	
	printf("stack_A: ");
	print_list(lst);

	printf("stack_B: ");
	print_list(stack_B);
	
}

void we_are_four(t_list **lst)
{
	
	find_push(*lst);
}