/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 10:09:08 by aroca-pa          #+#    #+#             */
/*   Updated: 2023/12/06 19:17:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft_42/libft.h"

//void	print_list(t_list *list);
int		check_order(t_list *lst);
int		checkerror(char **argv);
int		main(int argc, char *argv[]);
t_list *startstack(int argc, char **argv);
int	    check_duplicate(t_list *lst);
void	ft_isint(int nbr);
void	onetwothree(t_list **lst);
void	push(t_list **lstdst, t_list **head, char origin);
void	rotate_ra(t_list **lst);
void	rotate_rb(t_list **lst);
void	rotate_rr(t_list **lsta, t_list **lstb);
void	rotate_rra(t_list **lst);
void	rotate_rrb(t_list **lst);
void	swap_sa(t_list **lst);
void	swap_sb(t_list **lst);
void	swap_ss(t_list **lsta, t_list **lstb);
void    ft_isint(int nbr);
void    rotate_rrr(t_list **lsta, t_list **lstb);
void	four_or_five(t_list **lst);
void	print_list(t_list *list);
void	magic_swap(t_list **lst);
#endif
