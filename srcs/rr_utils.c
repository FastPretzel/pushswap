/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:57:00 by cgoth             #+#    #+#             */
/*   Updated: 2022/02/17 15:57:36 by cgoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_h.h"

void	rra(t_list **lst, int val)
{
	int		size;
	t_list	*elem;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	elem = *lst;
	size = ft_lstsize(*lst);
	while (size-- > 2)
		elem = elem->next;
	*lst = ft_lstadd_front(*lst, ft_lstlast(*lst));
	elem->next = NULL;
	if (val && write(1, "rra\n", 4))
		;
}

void	rrb(t_list **lst, int val)
{
	int		size;
	t_list	*elem;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	elem = *lst;
	size = ft_lstsize(*lst);
	while (size-- > 2)
		elem = elem->next;
	*lst = ft_lstadd_front(*lst, ft_lstlast(*lst));
	elem->next = NULL;
	if (val && write(1, "rrb\n", 4))
		;
}

void	rrr(t_list **alst, t_list **blst, int val)
{
	rra(alst, 0);
	rrb(blst, 0);
	if (val && write(1, "rrb\n", 4))
		;
}
