/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 07:01:53 by aroca-pa          #+#    #+#             */
/*   Updated: 2023/12/08 14:10:53 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <unistd.h>

void	push(t_list **lstdst, t_list **head, char origin)
{
	t_list	*save_head;

	if ((head && *head))
	{
		save_head = *head;
		*head = (*head)->next;
		ft_lstadd_front(lstdst, save_head);
	}
	if (origin == 'a')
		write(1, "pb\n", 3);
	else if (origin == 'b')
		write(1, "pa\n", 3);
}
