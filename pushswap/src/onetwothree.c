/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onetwothree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 01:00:59 by aroca-pa          #+#    #+#             */
/*   Updated: 2023/04/08 03:32:32 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_order(t_list **lst)
{
	while (lst && (*lst)->next)
	{
		if ((*lst)->content > (*lst)->next->content)
			return (0);
		*lst = (*lst)->next;
	}
	return (1);
}

void	onetwothree(t_list **lst)
{	
	int	*first_node;
	int	*second_node;	
	int	*third_node;

	first_node = (int *)(*lst)->content;
	second_node =  (int *)(*lst)->next->content;
	third_node = (int *)(*lst)->next->next->content;
	if (!lst || !(*lst) || !((*lst)->next))
		return ;
	while (!check_order(lst))
	{	
		if (first_node > second_node && second_node > third_node)
			rotate_ra(lst);
		else if (first_node < second_node && second_node > third_node)
			rotate_rra(lst);
		else
			swap_sa(lst);
	}
}
