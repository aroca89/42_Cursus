/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 07:12:02 by aroca-pa          #+#    #+#             */
/*   Updated: 2023/12/02 17:23:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <unistd.h>

static void	rotate(t_list **lst)
{
    t_list	*head;
    t_list	*last;

    if (lst && *lst && (*lst)->next)
    {
        head = *lst;
        *lst = (*lst)->next;
        head->next = NULL;

        last = *lst;
        while (last->next)
            last = last->next;

        last->next = head;
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
