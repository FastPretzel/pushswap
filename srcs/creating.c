/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:51:18 by cgoth             #+#    #+#             */
/*   Updated: 2022/02/17 15:51:43 by cgoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_h.h"

static void	put_index(int *arr, t_malloc *tmc, int size)
{
	int		i;
	int		flag;
	t_list	*node;

	node = tmc->a_st;
	while (node)
	{
		i = -1;
		flag = 0;
		while (++i < size && !flag)
		{
			if (arr[i] == *((int *)(node->content)))
			{
				node->index = i;
				flag = 1;
			}
		}
		node = node->next;
	}
}

static void	arr_sort(int *arr, int size, t_malloc *tmc)
{
	int	i;
	int	j;
	int	tmp;

	i = -1;
	while (++i < size)
	{
		j = size;
		while (--j > i)
		{
			if (arr[j - 1] > arr[j])
			{
				tmp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = tmp;
			}
		}
	}
	put_index(arr, tmc, size);
}

void	create_stack(t_malloc *tmc, int size)
{
	int	i;
	int	*arr;

	tmc->a_st = 0;
	i = -1;
	tmc->b_st = 0;
	while (++i < size)
		tmc->a_st = ft_lstadd_back(tmc->a_st, ft_lstnew(&(tmc->nums[i])));
	arr = malloc(sizeof(int) * size);
	if (!arr)
		clean(tmc);
	i = -1;
	while (++i < size)
		arr[i] = tmc->nums[i];
	arr_sort(arr, masslen(tmc->av), tmc);
	free(arr);
}
