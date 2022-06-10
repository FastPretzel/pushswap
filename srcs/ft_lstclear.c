/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 19:26:35 by cgoth             #+#    #+#             */
/*   Updated: 2022/02/17 15:55:00 by cgoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_h.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*elem;
	t_list	*buf;

	if (!lst)
		return ;
	elem = *lst;
	while (elem)
	{
		buf = elem;
		elem = elem->next;
		free(buf);
	}
	*lst = elem;
}
