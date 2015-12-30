/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_chain.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 20:19:48 by yismail           #+#    #+#             */
/*   Updated: 2015/12/30 21:51:31 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>


char **create_tab (char *buf)
{
  int col;
  int lin;
  int i;
  char **tab;
  int j;
  int f;

  col = 0;
  lin = 0;
  i = 0;
  while (i < 21)
	{
	  col = 0;
	  while (buf[i] != '\n')
		{
		  col++;
		  i++;
		}
	  lin ++;
	  i++;
	}

  tab = malloc(sizeof(char*) * lin);
  if (tab == NULL)
	return (0);
  j = 0;
  while (j < col)
	{
	  tab[j] = malloc (sizeof(char) * col);
		j++;
	}
  
  lin = 0;
  col = 0;
  
  while (i < 21)
	{
	  f = 0;
	  while (f < 5 && buf[i] != '\n')
		{
		  tab[lin][col] = buf[i];
		  col++;
		  i++;
		}
	  lin++;
	}

return (tab);
}
int main (void)
{
  char *str;
  char **tab;
  
  str = "..#.\n..#.\n...#\n.#..\n\n";
  tab = create_tab(str);
  printf ("%s", tab[1]);
  return (0);
}
