/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shuffle3_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:59:02 by cgoth             #+#    #+#             */
/*   Updated: 2022/02/17 16:09:20 by cgoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_h.h"

int	is_sorted(t_malloc *tmc, t_list **lst)
{
	t_list	*node;

	node = *lst;
	if (!node)
		clean(tmc);
	while (node->next)
	{
		if (node->index > node->next->index)
			return (0);
		node = node->next;
	}
	return (1);
}

static int	steps(t_list *lst, int idx)
{
	t_list	*tmp;
	int		res;

	tmp = lst;
	res = 0;
	while (tmp->index != idx)
	{
		tmp = tmp->next;
		res++;
	}
	return (res);
}

void	sort_for_3(t_malloc *tmc, int size)
{
	t_list	*last;

	last = ft_lstlast(tmc->a_st);
	if (size == 2)
		sa(&tmc->a_st, 1);
	else
	{
		if (tmc->a_st->index < last->index)
		{
			sa(&tmc->a_st, 1);
			if (tmc->a_st->index > ft_lstlast(tmc->a_st)->index)
				ra(&tmc->a_st, 1);
		}
		else
		{
			if (tmc->a_st->index > tmc->a_st->next->index)
			{
				ra(&tmc->a_st, 1);
				if (tmc->a_st->index > tmc->a_st->next->index)
					sa(&tmc->a_st, 1);
			}
			else
				rra(&tmc->a_st, 1);
		}
	}
}

void	sort_for_5(t_malloc *tmc, int size)
{
	int	idx;
	int	size_tmp;

	idx = -1;
	size_tmp = size;
	while (++idx < 2)
	{
		while (tmc->a_st->index != idx)
		{
			if (steps(tmc->a_st, idx) > size / 2)
				rra(&tmc->a_st, 1);
			else
				ra(&tmc->a_st, 1);
		}
		pb(&tmc->b_st, &tmc->a_st, 1);
	}
	if (!is_sorted(tmc, &tmc->a_st))
		sort_for_3(tmc, size);
	pa(&tmc->a_st, &tmc->b_st, 1);
	pa(&tmc->a_st, &tmc->b_st, 1);
	if (tmc->a_st->index > tmc->a_st->next->index)
		sa(&tmc->a_st, 1);
}
