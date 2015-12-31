/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_chain.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 20:19:48 by yismail           #+#    #+#             */
/*   Updated: 2015/12/31 01:38:53 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "../libft/libft.h"
char **create(char *piece)
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
	  if (!(tab[col] = (char *)malloc(sizeof(char) * 1)))
		return (0);
	  col++;
	}
  while (lin < 4)
	{
	  col = 0;
	  while (col < 4)
		{
		  tab[lin][col] = piece[i];
		  col++;
		  i++;
		}
	  i++;
	  lin++;
	}
  return(tab);
}

void take (char *buf)
{
  int i;
  int j;
  char *tmp;

  i = 0;
  j = 0;
  while (buf[i] != '\0')
	{
	  if (buf[i] == '\n' && buf[i + 1] == '\n')
		{
		  tmp = ft_strndup(buf, (i + 1));
		  printf ("%s", tmp);
		}
	  i++;
	}
}
  int main (void)
{
  char *str;
  char **tab;
  int i;
  int j;


  i = 0;
  str = ft_strdup("..#.\n..#.\n...#\n...#\n\n");
  take (str);
  return (0);
}
  /*
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
  */

