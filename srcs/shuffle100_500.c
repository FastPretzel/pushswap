/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shuffle100_500.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:58:33 by cgoth             #+#    #+#             */
/*   Updated: 2022/02/17 15:58:35 by cgoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_h.h"

static int	steps_to_max(t_list **lst, int inx)
{
	t_list	*tmp;
	int		res;

	res = 0;
	tmp = *lst;
	while (tmp)
	{
		if (tmp->index == inx)
			break ;
		res++;
		tmp = tmp->next;
	}
	return (res);
}

static void	sort_for_b(t_malloc *tmc, int size)
{
	int	inx;

	inx = size - 1;
	while (tmc->b_st)
	{
		if (tmc->b_st->index == size - 1)
		{
			pa(&tmc->a_st, &tmc->b_st, 1);
			size--;
		}
		else if (steps_to_max(&tmc->b_st, size - 1) <= size / 2)
			rb(&tmc->b_st, 1);
		else
			rrb(&tmc->b_st, 1);
	}
}

void	sort_for_100500(t_malloc *tmc, int size)
{
	int	inx;
	int	val;

	inx = 0;
	if (size < 102)
		val = 15;
	else
		val = 30;
	while (tmc->a_st)
	{
		if (tmc->a_st->index <= inx && inx > 1)
		{
			pb(&tmc->b_st, &tmc->a_st, 1);
			rb(&tmc->b_st, 1);
			inx++;
		}
		else if (tmc->a_st->index <= inx + val)
		{
			pb(&tmc->b_st, &tmc->a_st, 1);
			inx++;
		}
		else if (tmc->a_st->index >= inx)
			ra(&tmc->a_st, 1);
	}
	sort_for_b(tmc, size);
}
