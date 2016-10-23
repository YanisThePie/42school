/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_place.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 18:07:52 by jcazako           #+#    #+#             */
/*   Updated: 2016/01/21 12:11:54 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_range(char **tab, t_pos rg, int size)
{
	if (rg.x < 0 || rg.x >= size)
		return (0);
	if (rg.y < 0 || rg.y >= size)
		return (0);
	if (tab[rg.y][rg.x] != '.')
		return (0);
	return (1);
}

int			check_place(char **tab, t_tet *tet, t_pos i, int size)
{
	int		k;
	t_pos	j;
	t_pos	rg;

	k = 0;
	j.y = tet->ft.y - 1;
	while (++j.y < 4)
	{
		j.x = -1;
		while (++j.x < 4)
		{
			if (tet->shp[j.y][j.x] == '#')
			{
				rg.x = i.x + j.x - tet->ft.x;
				rg.y = i.y + j.y - tet->ft.y;
				k++;
				if (!check_range(tab, rg, size))
					return (0);
			}
			if (k == 4)
				return (1);
		}
	}
	return (1);
}
