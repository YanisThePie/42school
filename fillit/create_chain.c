/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_chain.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 20:19:48 by yismail           #+#    #+#             */
/*   Updated: 2015/12/30 23:52:53 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
  lin = (lin - 1);
  if (!(tab = (char **)malloc(sizeof(char *) * 16)))
	  return (0);
  j = 0;
  while (j < 5)
  {
	 tab[j] = (char *)malloc(sizeof(char) * 4);
	 j++;
  }
  
  lin = 0;
  i = 0;
  while (lin < 4)
	{
	  col = 0;
	  while (col < 4 && buf[i] != '\n')
		{
		  //  printf("%c", buf[i]);
		  tab[lin][col] = buf[i];
		  col++;
		  i++;
		}
	  lin++;
	}

return (tab);
}

char **create(char *buf)
{
  char **tab;
  int lin;
  int col;
  int i;

  i = 0;
  lin = 0;
  col = 0;
  if (!(tab = (char **)malloc(sizeof(char *) * 16)))
 	return (0);
  while (col < 4)
  {
  	tab[col] = (char *)malloc(sizeof(char) * 1);
	col++;
  }
  while (lin < 4)
  {
	   col = 0;
	   while (col < 4)
	   {
		 tab[lin][col] = buf[i];
		 col++;
		 i++;
	   }
	   i++;
	   lin++;
  }
  return(tab);
}


int main (void)
{
  char *str;
  char **tab;
  int i;
  int j;


  i = 0;
  str = "..#.\n..#.\n...#\n.##.\n\n";
  tab = create(str);
  while (i < 4)
  {
	j = 0;
	while (j < 4)
	{
	  printf("%c", tab[i][j]);
	  j++;
	}
	printf("\n");
	i++;
  }
  return (0);
}
