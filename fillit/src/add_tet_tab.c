/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_tet_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 17:37:16 by jcazako           #+#    #+#             */
/*   Updated: 2016/01/21 12:03:56 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		add_tet_tab(char **tab, t_tet *tet, t_pos i)
{
	int		k;
	t_pos	j;
	t_pos	rg;

	k = 0;
	j.y = tet->ft.y;
	while (j.y < 4)
	{
		j.x = 0;
		while (j.x < 4)
		{
			if (tet->shp[j.y][j.x] == '#')
			{
				rg.x = i.x + j.x - tet->ft.x;
				rg.y = i.y + j.y - tet->ft.y;
				tab[rg.y][rg.x] = tet->ch;
				k++;
			}
			if (k == 4)
				return ;
			j.x++;
		}
		j.y++;
	}
}
