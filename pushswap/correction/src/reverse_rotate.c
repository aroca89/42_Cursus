/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 04:09:47 by aroca-pa          #+#    #+#             */
/*   Updated: 2023/12/02 17:26:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <unistd.h>

static void	rotate_r(t_list **lst)
{
    t_list	*last;
    t_list	*prev = NULL;

    if (lst && *lst)
    {
        last = *lst;
        while (last->next)
        {
            prev = last;
            last = last->next;
        }
        if (prev)
        {
            prev->next = NULL;
            last->next = *lst;
            *lst = last;
        }
    }
}

void	rotate_rra(t_list **lst)
{
	if (lst && *lst)
		rotate_r(lst);
	write(1, "rra\n", 4);
}

void	rotate_rrb(t_list **lst)
{
	if (lst && *lst)
		rotate_r(lst);
	write(1, "rrb\n", 4);
}

void	rotate_rrr(t_list **lsta, t_list **lstb)
{
	if ((lsta && *lsta) && (lstb && *lstb))
	{
		rotate_rra(lsta);
		rotate_rrb(lstb);
	}
	write(1, "rrr\n", 4);
}
