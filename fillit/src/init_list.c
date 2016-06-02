/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 13:05:21 by jcazako           #+#    #+#             */
/*   Updated: 2016/01/21 12:11:23 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	init_first(t_tet *tet)
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
				tet->ft.x = i.x;
				tet->ft.y = i.y;
				return ;
			}
			i.x++;
		}
		i.y++;
	}
}

static void	init_shape(t_tet *tet, char **str)
{
	t_pos	j;

	j.y = 0;
	while (j.y < 4)
	{
		j.x = 0;
		while (j.x < 4)
		{
			tet->shp[j.y][j.x] = **str;
			(*str)++;
			j.x++;
		}
		(*str)++;
		j.y++;
	}
}

t_tet		*init_list(char *str, int nb_tet)
{
	int		i;
	t_tet	*tet;
	t_tet	*first;

	if (!(tet = tet_new('A')))
		return (NULL);
	first = tet;
	i = 1;
	while (i < nb_tet)
	{
		add_tet_list(first);
		i++;
	}
	i = 0;
	while (i < nb_tet)
	{
		init_shape(tet, &str);
		init_first(tet);
		str++;
		i++;
		tet = tet->next;
	}
	return (first);
}
