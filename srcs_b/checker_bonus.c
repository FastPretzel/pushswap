/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:46:30 by cgoth             #+#    #+#             */
/*   Updated: 2022/02/17 17:19:46 by cgoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_h.h"

typedef void	(*t_f1)(t_list **, int);
typedef void	(*t_f2)(t_list **, t_list **, int);

int	*buf_num(char **buf, t_malloc *tmc)
{
	int	i;
	int	*nums;

	i = -1;
	if (!buf || !*buf)
		return (0);
	nums = malloc(sizeof(int) * masslen(buf));
	if (!nums)
		clean(tmc);
	while (buf[++i])
		fill_nums(tmc, nums, buf[i], i);
	i = -1;
	while (buf[++i])
		free(buf[i]);
	free(buf);
	return (nums);
}

int	*buf_init(t_malloc *tmc)
{
	char	*line;
	char	*buf;
	int		*res;

	buf = 0;
	res = 0;
	line = get_next_line(0);
	while (line)
	{
		buf = ft_strjoin(buf, line);
		free(line);
		line = get_next_line(0);
		tmc->buf_size++;
	}
	free(line);
	res = buf_num(ft_split(buf, '\n'), tmc);
	free(buf);
	return (res);
}

void	fns_parse(t_malloc *tmc, void **fnctns, int *av)
{
	int	i;

	i = -1;
	if (!av)
		return ;
	while (++i < tmc->buf_size)
	{
		if (av[i] >= 0 && av[i] <= 2)
			((t_f1)(fnctns[av[i]]))(&tmc->a_st, 0);
		else if (av[i] >= 3 && av[i] <= 5)
			((t_f1)(fnctns[av[i]]))(&tmc->b_st, 0);
		else if (av[i] >= 6 && av[i] <= 9)
			((t_f2)(fnctns[av[i]]))(&tmc->a_st, &tmc->b_st, 0);
		else if (av[i] == 10)
			((t_f2)(fnctns[av[i]]))(&tmc->b_st, &tmc->a_st, 0);
	}
	free(av);
}

void	check_st(t_malloc *tmc, int size)
{
	if (is_sorted(tmc, &tmc->a_st) && \
			ft_lstsize(tmc->a_st) == size && !tmc->b_st)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_malloc	tmc;
	int			size;

	if (argc < 2)
		return (0);
	tmc.av = separ(argv, &tmc);
	size = masslen(tmc.av);
	if (!size)
		clean(&tmc);
	tmc.nums = stoi(tmc.av, size, &tmc);
	if (!tmc.nums)
		clean(&tmc);
	create_stack(&tmc, size);
	tmc.buf_size = 0;
	fns_parse(&tmc, ptrs_init(), buf_init(&tmc));
	check_st(&tmc, size);
	clean(&tmc);
	return (0);
}
