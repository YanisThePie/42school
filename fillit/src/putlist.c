/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putlist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 13:51:10 by jcazako           #+#    #+#             */
/*   Updated: 2015/12/23 17:27:16 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	putlist(t_tet *tet)
{
	t_pos	i;

	while (tet)
	{
		i.y = 0;
		while (i.y < 4)
		{
			i.x = 0;
			while (i.x < 4)
			{
				ft_putchar(tet->shp[i.y][i.x]);
				i.x++;
			}
			ft_putchar('\n');
			i.y++;
		}
		ft_putchar('\n');
		tet = tet->next;
	}
}
