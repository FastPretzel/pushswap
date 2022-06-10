/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:27:45 by cgoth             #+#    #+#             */
/*   Updated: 2022/02/17 14:57:44 by cgoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_h.h"

static int	m_clear(char **str, int size)
{
	while (size--)
		free(str[size]);
	return (-1);
}

static int	n_words(const char *s, char c)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			len++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (len);
}

static void	wr_word(char *dst, char const *src, char c)
{
	int	i;

	i = 0;
	while (src[i] != c && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

static int	wr_words(char **str, char const *s, char c)
{
	int	w_len;
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!n_words(s, c))
		return (m_clear(str, n_words(s, c)));
	while (s[i] && j < n_words(s, c))
	{
		w_len = 0;
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			w_len++;
			i++;
		}
		str[j] = malloc(sizeof(char) * (w_len + 1));
		if (!(str[j]))
			return (m_clear(str, j - 1));
		wr_word(str[j++], s + i - w_len, c);
	}
	str[j] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		k;
	char	**str;

	str = (char **)malloc(sizeof(char *) * (n_words(s, c) + 1));
	if (!str)
		return (NULL);
	k = wr_words(str, s, c);
	if (k == -1)
		return (NULL);
	return (str);
}
