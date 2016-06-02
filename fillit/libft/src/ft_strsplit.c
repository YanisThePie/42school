/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 11:17:11 by jcazako           #+#    #+#             */
/*   Updated: 2015/12/07 15:55:39 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		gt_wordnb(const char *str, char a)
{
	int		i;

	i = 0;
	if (!str || !a)
	{
		return (0);
	}
	while (*str)
	{
		while (*str == a)
		{
			str++;
		}
		if (*str && *str != a)
		{
			while (*str && *str != a)
			{
				str++;
			}
			i++;
		}
	}
	return (i);
}

static size_t	gt_wordln(const char *str, char a)
{
	size_t	ln;

	ln = 0;
	while (*str && *str != a)
	{
		ln++;
		str++;
	}
	return (ln);
}

static char		*gt_word(const char **str, char a)
{
	size_t	len_w;
	char	*word;
	int		i;

	len_w = 0;
	word = NULL;
	i = 0;
	while (**str == a)
		(*str)++;
	len_w = gt_wordln(*str, a);
	word = (char*)malloc(sizeof(*word) * len_w + 1);
	if (!word)
	{
		return (NULL);
	}
	while (i < (int)len_w)
	{
		word[i] = *(*str)++;
		i++;
	}
	word[i] = '\0';
	while (**str == a)
		(*str)++;
	return (word);
}

static char		**ft_strnull(void)
{
	char	**tab;

	tab = NULL;
	tab = (char**)malloc(sizeof(*tab) + 1);
	if (!tab)
	{
		return (NULL);
	}
	*tab = NULL;
	return (tab);
}

char			**ft_strsplit(const char *str, char a)
{
	int		nb_word;
	char	**tab;

	nb_word = gt_wordnb(str, a);
	tab = NULL;
	if (!str || !a || !nb_word)
	{
		return (ft_strnull());
	}
	tab = (char**)malloc(sizeof(*tab) * nb_word + 1);
	if (!tab)
	{
		return (NULL);
	}
	while (*str)
	{
		*tab++ = gt_word(&str, a);
	}
	*tab = NULL;
	return (tab - nb_word);
}
