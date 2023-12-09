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
	write(1, "ra\n", 3);
}

void	rotate_rb(t_list **lst)
{	
	if (lst && *lst)
		rotate(lst);
	write(1, "rb\n", 3);
}

void	rotate_rr(t_list **lsta, t_list **lstb)
{
	if ((lsta && *lsta) && (lstb && *lstb))
	{
		rotate_ra(lsta);
		rotate_rb(lstb);
	}
	write(1, "rr\n", 3);
}
