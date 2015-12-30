/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_chain.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 20:19:48 by yismail           #+#    #+#             */
/*   Updated: 2015/12/30 21:29:50 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int **create_tab (char *buf)
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
	  tab[j] = malloc (sizeof(char) * col)
		j++;
	}
  
  lin = 0;
  col = 0;
 
  while (i < 21)
	{
	  f = 0;
	  while (f < 5)
		{
		  tab[lin][col2] = buf[i];
		  col++;
		  i++;
		}
		lin++;
		}
	}
