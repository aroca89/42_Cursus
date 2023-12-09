/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onetwothree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 01:00:59 by aroca-pa          #+#    #+#             */
/*   Updated: 2023/12/08 14:11:01 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdint.h>
#include  <stdio.h>

int	check_order(t_list *lst)
{
	t_list *temp;

	temp = lst;
	while (temp && temp->next)
	{
		if (temp->content > temp->next->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	onetwothree(t_list **lst)
{
	int first_node;
	int	second_node;
	int third_node;

	if (!lst || !(*lst) || !((*lst)->next) || !((*lst)->next->next))
		return ;
	while (!check_order(*lst))
	{
		first_node = (int)(intptr_t)((*lst)->content);
		second_node = (int)(intptr_t)((*lst)->next->content);
		third_node = (int)(intptr_t)((*lst)->next->next->content);

		if (first_node > second_node && second_node < third_node && first_node < third_node)
			swap_sa(lst);
		else if (first_node > second_node && second_node > third_node)
			rotate_ra(lst);
		else if (first_node > second_node && second_node < third_node && first_node > third_node)
			rotate_rra(lst);
		else if (first_node < second_node && second_node > third_node)
			rotate_rra(lst);
	}
}
