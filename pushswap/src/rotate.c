/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroca-pa <aroca-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 07:12:02 by aroca-pa          #+#    #+#             */
/*   Updated: 2023/04/08 02:52:37 by aroca-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <unistd.h>

static void	rotate(t_list **lst)
{
	t_list	*head;

	if (lst && *lst)
	{
		head = (*lst)->next;
		(*lst)->next = NULL;
		ft_lstadd_back(*lst, &head);
		*lst = head;
	}
}

void	rotate_ra(t_list **lst)
{
	if (lst && *lst)
		rotate(lst);
	write(2, "\033[1;32mRa\n\033[0m", 14);
}

void	rotate_rb(t_list **lst)
{	
	if (lst && *lst)
		rotate(lst);
	write(2, "\033[1;32mRb\n\033[0m", 14);
}

void	rotate_rr(t_list **lsta, t_list **lstb)
{
	if ((lsta && *lsta) && (lstb && *lstb))
	{
		rotate_ra(lsta);
		rotate_rb(lstb);
	}
	write(2, "\033[1;32mRr\n\033[0m", 14);
}
