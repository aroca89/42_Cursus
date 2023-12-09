/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   beta_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 22:08:35 by aroca-pa          #+#    #+#             */
/*   Updated: 2023/12/09 13:31:25 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


static int get_pivot(t_list *lst)
{
	int index;
	int size;
	int number_content;

	index = 0;
	size = ft_lstsize(lst) /2 ;
	while (index < size && lst != NULL)
	{
		number_content = (int)(intptr_t)lst->content;
		index++;
		lst = lst->next;
	}
	return (number_content);
}

static int get_pivot(t_list *lst)
{
	int min = INT_MAX;
	int max = INT_MIN;

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

static int find_extremes (t_list *lst, int operation)
{
	t_list *temp;
	t_list *extreme;
	int index;
	int index_extreme;

	temp = lst;
	extreme = temp;
	index = 0;
	index_extreme = 0;
	while (temp)
	{
		//printf("El valor más pequeño es: %d\n", (int)(intptr_t)extreme->content);
		if (operation == 1 && ((int)(intptr_t)extreme->content > (int)(intptr_t)temp->content))
		{
			extreme = temp;
			index_extreme = index;
		}
		else if (operation == 2 && ((int)(intptr_t)extreme->content < (int)(intptr_t)temp->content))
		{
			extreme = temp;
			index_extreme = index;
		}
		temp = temp->next;
		index++;
		//printf("indice >>> %d\n", index);
	}
	return index_extreme;
}

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