/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 07:07:20 by aroca-pa          #+#    #+#             */
/*   Updated: 2023/04/08 03:01:58 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <unistd.h>

static void	swap(t_list **lst)
{
	t_list	*second;

	if (lst)
	{
		second = (*lst)->next;
		(*lst)->next = second->next;
		second->next = *lst;
		*lst = second;
	}	
}

void	swap_sa(t_list **lst)
{
	if (lst && *lst)
		swap(lst);
	write(1, "sa\n", 3);
}

void	swap_sb(t_list **lst)
{	
	if (lst && *lst)
		swap(lst);
	write(1, "sb\n", 3);
}

void	swap_ss(t_list **lsta, t_list **lstb)
{
	if ((lsta && *lsta) && (lstb && *lstb))
	{
		swap_sa(lsta);
		swap_sb(lstb);
	}
	write(1, "ss\n", 3);
}
