/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_first.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 18:17:33 by jcazako           #+#    #+#             */
/*   Updated: 2015/12/23 18:18:50 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	check_first(t_tet *tet, t_pos *first)
{
	t_pos	i;

	i.y = 0;
	while (i.y < 4)
	{
		i.x = 0;
		while (i.x < 4)
		{
			if (tet->shp[i.y][i.x] == '#')
			{
				first->x = i.x;
				first->y = i.y;
				return ;
			}
			i.x++;
		}
		i.y++;
	}
}
