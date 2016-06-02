/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 19:36:06 by jcazako           #+#    #+#             */
/*   Updated: 2015/12/23 20:03:49 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			fillit(char **tab, t_tet *tet, int size)
{
	t_pos	i;

	if (!tet)
		return (1);
	i.y = 0;
	while (i.y < size)
	{
		i.x = 0;
		while (i.x < size)
		{
			if (check_place(tab, tet, i, size))
			{
				add_tet_tab(tab, tet, i);
				if (fillit(tab, tet->next, size))
					return (1);
				del_tet_tab(tab, tet, i);
			}
			i.x++;
		}
		i.y++;
	}
	return (0);
}
