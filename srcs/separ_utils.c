/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separ_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:57:47 by cgoth             #+#    #+#             */
/*   Updated: 2022/02/18 19:12:57 by cgoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_h.h"

int	masslen(char **str)
{
	int	i;
	int	size;

	i = -1;
	size = 0;
	if (str && *str)
	{
		while (str[++i])
			size++;
	}
	return (size);
}

static char	**concat(char **dest, char **str, t_malloc *tmc)
{
	int		i;
	int		j;
	int		size;
	char	**res;

	i = 0;
	size = masslen(dest) + masslen(str);
	if (!size)
		return (0);
	res = (char **)malloc(sizeof(char *) * (size + 1));
	if (!res)
		clean(tmc);
	if (dest && *dest)
	{
		while (dest[i])
		{
			res[i] = dest[i];
			i++;
		}
	}
	j = -1;
	while (str[++j])
		res[i++] = str[j];
	res[i] = 0;
	free(str);
	free(dest);
	return (res);
}

char	**separ(char **argv, t_malloc *tmc)
{
	int		i;
	char	**res;

	res = 0;
	i = 0;
	while (argv[++i])
		res = concat(res, ft_split(argv[i], ' '), tmc);
	if (!res)
		clean(tmc);
	return (res);
}
