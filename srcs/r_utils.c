/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:56:52 by cgoth             #+#    #+#             */
/*   Updated: 2022/02/17 15:56:54 by cgoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_h.h"

void	ra(t_list **lst, int val)
{
	t_list	*first;
	t_list	*last;
	t_list	*curr;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	first = *lst;
	curr = (*lst)->next;
	last = ft_lstlast(curr);
	last->next = first;
	first->next = NULL;
	*lst = curr;
	if (val && write(1, "ra\n", 3))
		;
}

void	rb(t_list **lst, int val)
{
	t_list	*first;
	t_list	*last;
	t_list	*curr;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	first = *lst;
	curr = (*lst)->next;
	last = ft_lstlast(curr);
	last->next = first;
	first->next = NULL;
	*lst = curr;
	if (val && write(1, "rb\n", 3))
		;
}

void	rr(t_list **alst, t_list **blst, int val)
{
	ra(alst, 0);
	rb(blst, 0);
	if (val && write(1, "rr\n", 3))
		;
}
