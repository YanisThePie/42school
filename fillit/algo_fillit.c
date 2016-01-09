/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_fillit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 16:50:13 by yismail           #+#    #+#             */
/*   Updated: 2016/01/09 15:08:59 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// unsigned int	square[32];

int		get_minimal_size(t_dlist *list)
{
	int i;
	int j;

	i = 0;
	j = 2;
	while (list)
	{
		list = list->next;
		i++;
	}
	while (j * j < i * 4)
		j++;
	return (j);
}

void	set_square(unsigned int *square, int size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 32)
		square[i++] = '.';
	i = 0;
	while (j < size)
	{
		while (i < size)
		{
			square[j] &= ~(1 << (31 - i));
			i++;
		}
		j++;
		i = 0;
	}
}

int		place(t_dlist *tetri, unsigned int *square, int size)
{
	int i;
	int j;

	i = tetri->x;
	j = tetri->y;
	while (j < size)
	{
		while (i < size)
		{
			if(fit(tetri->mask, square, i, j))
			{
				stamp(tetri->mask, square, i, j);
				tetri->x = i;
				tetri->y = j;
				return (1);
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}

int		fit(unsigned int *piece, unsigned int *square, int x, int y)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (piece[i] >> x & square[y + i])
			return (0);
		i++;
	}
	return (1);
}

void	stamp(unsigned int *piece, unsigned int *square, int x, int y)
{
	int i;

	i = 0;
	while (i < 4)
	{
		square[y + i] |= piece[i] >> x;
		i++;
	}
}

int             resolve(t_dlist *list, unsigned int *square)
{
  int a;

  a = get_minimal_size(list);
  set_square(square, a);
  while (1)
    {
      if (place(list->content, square, a))
	list = list->next;
      else
	{
	  if (list->prev)
	    {
	      list = list->prev;
	    }
	  else
	    {
	      set_square(square, ++a);
	      ((t_dlist *)list->content)->x = 0;
	      ((t_dlist *)list->content)->y = 0;
	    }
	}
      if (!list)
	return (a);
    }
}
