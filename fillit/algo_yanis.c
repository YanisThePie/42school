/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_yanis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 17:46:54 by yismail           #+#    #+#             */
/*   Updated: 2016/01/11 08:48:03 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void print_it (char **tab)
{
	int i;
	
	i = 0;
	ft_putstr (tab[i]);
	i++;
	ft_putstr (tab[i]);
	i++;
	ft_putstr (tab[i]);
}

char **malloc_square (size_t size)
{
	char **square;
	size_t i;
	size_t j;
	i = 0;
	j = 0;
	square = (char**)malloc (sizeof(char*) * (size * size) + 1);
	while (i <= size)
	{	
		square[i] = (char*)malloc(sizeof(char) * (size) + 1);
		i++;
    }
	i = 0;
	while (i < size)
    {
		j = 0;
		while (j < size)
		{
			square[i][j] = '.';
			j++;
		}
      square[i][j] = '\n';
      i++;
    }
	return (square);		
}

int is_right (char **square, int lin, int col,int size)
{
  if (n > 0)
	  return (0);
  if (square[lin][col] == '\0')
	  return (1);
  //if (col == size)
  //{
  //ft_putnbr(lin);
  //ft_putchar('L');
  //ft_putchar ('\n');
  //	lin = lin + 1;
  //	col = -1;
  //}
  if(square[lin][col] == '.' && (col < size))
  {
      if((verif_tetri(square[lin][col], list->content)) == 1)
		  n--;
      return (is_right(square, lin, col+1, size));
  }
  else
  {
      if (lin < size)
	  {
		  col = -1;
		  return (is_right(square, lin + 1, col + 1, size));
	  }
  }
  return (0);
}

int place_in_square (t_dlist *list)
{
	char **square;
	int size;
	int result;
	
	list = NULL;//a retirer
	size = 2;
	square = malloc_square(size);
	result = is_right(square, 0, 0, size);
	//ft_putnbr (result);
	print_it (square);
	return (0);
}
