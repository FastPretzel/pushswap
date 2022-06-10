/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:51:48 by cgoth             #+#    #+#             */
/*   Updated: 2022/02/17 17:18:45 by cgoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_h.h"

static void	non_num(char **av, t_malloc *tmc)
{
	int	i;
	int	j;

	i = -1;
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
		{
			if (j != 0 && av[i][j] == '-')
				ft_err(tmc);
			if (j == 0 && !((av[i][j] >= '0' && \
							av[i][j] <= '9') || av[i][j] == '-'))
				ft_err(tmc);
		}
	}
}

static void	duplic(int *nums, int size, t_malloc *tmc)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size - 1)
	{
		j = size - 1;
		while (j > i)
			if (nums[i] == nums[j--])
				ft_err(tmc);
	}
}

void	ft_err(t_malloc *tmc)
{
	write(2, "Error\n", 6);
	clean(tmc);
}

static void	check_minus(char **av, t_malloc *tmc)
{
	int	i;
	int	j;

	i = -1;
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
			if (av[i][j] == '-' && (!av[i][j + 1] || (av[i][j + 1] && \
							!(av[i][j + 1] >= '0' && av[i][j + 1] <= '9'))))
				ft_err(tmc);
	}
}

int	*stoi(char **av, int size, t_malloc *tmc)
{
	int	*nums;
	int	i;

	i = -1;
	non_num(av, tmc);
	nums = malloc(sizeof(int) * size);
	if (!nums)
		clean(tmc);
	check_minus(av, tmc);
	while (av[++i])
		nums[i] = ft_atoi(av[i], tmc);
	duplic(nums, size, tmc);
	return (nums);
}
