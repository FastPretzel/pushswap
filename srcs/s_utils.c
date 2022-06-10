/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:57:41 by cgoth             #+#    #+#             */
/*   Updated: 2022/02/17 16:10:13 by cgoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_h.h"

void	sa(t_list **lst, int val)
{
	t_list	*lst1;
	t_list	*lst2;
	t_list	*tmp;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	lst1 = *lst;
	lst2 = (*lst)->next;
	tmp = lst2->next;
	lst2->next = lst1;
	lst1->next = tmp;
	*lst = lst2;
	if (val && write(1, "sa\n", 3))
		;
}

void	sb(t_list **lst, int val)
{
	t_list	*lst1;
	t_list	*lst2;
	t_list	*tmp;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	lst1 = *lst;
	lst2 = (*lst)->next;
	tmp = lst2->next;
	lst2->next = lst1;
	lst1->next = tmp;
	*lst = lst2;
	if (val && write(1, "sb\n", 3))
		;
}

void	ss(t_list **alst, t_list **blst, int val)
{
	sa(alst, 0);
	sb(blst, 0);
	if (val && write(1, "ss\n", 3))
		;
}
