/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_tabnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 17:09:09 by jcazako           #+#    #+#             */
/*   Updated: 2015/12/23 17:33:09 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	init_tab(char **tab, int size)
{
	t_pos	i;

	i.y = 0;
	while (i.y < size)
	{
		i.x = 0;
		while (i.x < size)
		{
			tab[i.y][i.x] = '.';
			i.x++;
		}
		i.y++;
	}
}

char		**db_tabnew(int size)
{
	int		i;
	char	**db_tab;

	i = 0;
	if (!(db_tab = (char**)malloc(sizeof(*db_tab) * (size + 1))))
		return (NULL);
	db_tab[size] = NULL;
	while (i < size)
	{
		if (!(db_tab[i] = ft_strnew(size)))
			return (NULL);
		i++;
	}
	init_tab(db_tab, size);
	return (db_tab);
}
