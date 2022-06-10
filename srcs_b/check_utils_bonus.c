/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:42:45 by cgoth             #+#    #+#             */
/*   Updated: 2022/02/17 15:43:08 by cgoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_h.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (str1[i] || str2[i])
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

void	**ptrs_init(void)
{
	static void	*fnctns[11];

	fnctns[0] = sa;
	fnctns[1] = ra;
	fnctns[2] = rra;
	fnctns[3] = sb;
	fnctns[4] = rb;
	fnctns[5] = rrb;
	fnctns[6] = ss;
	fnctns[7] = rr;
	fnctns[8] = rrr;
	fnctns[9] = pa;
	fnctns[10] = pb;
	return (fnctns);
}

void	fill_nums(t_malloc *tmc, int *nums, char *str, int i)
{
	if (!ft_strcmp(str, "sa"))
		nums[i] = 0;
	else if (!ft_strcmp(str, "ra"))
		nums[i] = 1;
	else if (!ft_strcmp(str, "rra"))
		nums[i] = 2;
	else if (!ft_strcmp(str, "sb"))
		nums[i] = 3;
	else if (!ft_strcmp(str, "rb"))
		nums[i] = 4;
	else if (!ft_strcmp(str, "rrb"))
		nums[i] = 5;
	else if (!ft_strcmp(str, "ss"))
		nums[i] = 6;
	else if (!ft_strcmp(str, "rr"))
		nums[i] = 7;
	else if (!ft_strcmp(str, "rrr"))
		nums[i] = 8;
	else if (!ft_strcmp(str, "pa"))
		nums[i] = 9;
	else if (!ft_strcmp(str, "pb"))
		nums[i] = 10;
	else
		ft_err(tmc);
}
