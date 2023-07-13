/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 07:01:53 by aroca-pa          #+#    #+#             */
/*   Updated: 2023/04/08 02:51:19 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <unistd.h>

void	push(t_list **lstdst, t_list **head, char origin)
{
	t_list	*save_head;

	if ((lstdst && *lstdst) && (head && *head))
	{
		save_head = *head;
		*head = (*head)->next;
		ft_lstadd_front(lstdst, save_head);
	}
	if (origin == 'a')
		write(2, "\033[1;33mPa\n\033[0m", 14);
	else if (origin == 'b')
		write(2, "\033[1;33mPb\n\033[0m", 14);
}
