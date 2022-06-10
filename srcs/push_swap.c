/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:55:26 by cgoth             #+#    #+#             */
/*   Updated: 2022/02/17 16:08:31 by cgoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_h.h"

static void	shuffle(t_malloc *tmc, int size)
{
	if (!is_sorted(tmc, &tmc->a_st))
	{
		if (size <= 3)
			sort_for_3(tmc, size);
		else if (size <= 5)
			sort_for_5(tmc, size);
		else
			sort_for_100500(tmc, size);
	}
}

int	main(int argc, char **argv)
{
	t_malloc	tmc;
	t_list		*tmp;
	int			size;

	if (argc < 2)
		return (0);
	tmc.av = separ(argv, &tmc);
	size = masslen(tmc.av);
	tmc.nums = stoi(tmc.av, size, &tmc);
	if (!tmc.nums)
		clean(&tmc);
	create_stack(&tmc, size);
	shuffle(&tmc, size);
	tmp = tmc.a_st;
	clean(&tmc);
}
