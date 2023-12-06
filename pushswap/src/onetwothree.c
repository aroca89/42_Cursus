/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onetwothree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 01:00:59 by aroca-pa          #+#    #+#             */
/*   Updated: 2023/12/02 17:12:45 by marvin           ###   ########.fr       */
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
	if (!lst || !(*lst) || !((*lst)->next) || !((*lst)->next->next))
		return; // Asegurarse de que haya al menos 3 nodos

	while (!check_order(*lst)) // Pasar lst directamente, no modificar dentro de check_order
	{
		int first_node = (int)(intptr_t)((*lst)->content);
		int second_node = (int)(intptr_t)((*lst)->next->content);
		int third_node = (int)(intptr_t)((*lst)->next->next->content);

		printf("First: %d, Second: %d, Third: %d\n", first_node, second_node, third_node);


		// Cubrir todos los casos posibles para 3 elementos
		if (first_node > second_node && second_node < third_node && first_node < third_node)
			swap_sa(lst); // Caso: 2, 1, 3
		else if (first_node > second_node && second_node > third_node)
			rotate_ra(lst); // Caso: 3, 2, 1
		else if (first_node > second_node && second_node < third_node && first_node > third_node)
			rotate_rra(lst); // Caso: 3, 1, 2
		else if (first_node < second_node && second_node > third_node)
			rotate_rra(lst); // Caso: 1, 3, 2
	}
}
