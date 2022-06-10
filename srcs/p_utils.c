/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:55:10 by cgoth             #+#    #+#             */
/*   Updated: 2022/02/17 15:55:13 by cgoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_h.h"

void	pa(t_list **alst, t_list **blst, int val)
{
	t_list	*elem;

	if (!blst || !*blst)
		return ;
	elem = *blst;
	*blst = (*blst)->next;
	*alst = ft_lstadd_front(*alst, elem);
	if (val && write(1, "pa\n", 3))
		;
}

void	pb(t_list **blst, t_list **alst, int val)
{
	t_list	*elem;

	if (!alst || !*alst)
		return ;
	elem = *alst;
	*alst = (*alst)->next;
	*blst = ft_lstadd_front(*blst, elem);
	if (val && write(1, "pb\n", 3))
		;
}
