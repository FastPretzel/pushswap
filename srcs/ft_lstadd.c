/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:54:30 by cgoth             #+#    #+#             */
/*   Updated: 2022/02/17 15:54:39 by cgoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_h.h"

t_list	*ft_lstadd_back(t_list *lst, t_list *new_lst)
{
	t_list	*tmp;

	if (!lst)
	{
		lst = new_lst;
		return (lst);
	}
	tmp = ft_lstlast(lst);
	new_lst->next = tmp->next;
	tmp->next = new_lst;
	return (lst);
}

t_list	*ft_lstadd_front(t_list *lst, t_list *new_lst)
{
	if (!lst)
		new_lst->next = NULL;
	else
		new_lst->next = lst;
	lst = new_lst;
	return (lst);
}
