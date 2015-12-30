/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 17:35:39 by yismail           #+#    #+#             */
/*   Updated: 2015/12/30 19:47:28 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define OK 1
#define ERROR 0
#include <stdio.h>
int checksides(char *content)
{
  int n;
  int j;

  n = 0;
  j = 0;

  while (content[n] != '\0')
	{
		if (content[n] == '#')
		  {
			if (content[n + 5] == '#')
			  j++;
			if (content[n - 5] == '#')
			  j++;
			if (content[n + 1] == '#')
			  j++;
			if (content[n - 1] == '#')
			  j++;
		  }	
		n++;
	}


  //  while (tab)
  // {
  //  col = 0;
  //  while (tab[line][col] != '\n')
  //{
  //  if (tab[line][col] == '#')
  //    { 
  //      if (tab[line + 1][col] == '#')
  //		n++;
  //	  if (tab[line][col + 1] == '#')
  //		n++;
  //      if (tab[line - 1][col] == '#')
  //		n++;
  //      if (tab[line][col - 1] == '#')
  //		n++;
  //    }
  //  col++;
  //}
  //  line++;
  //}
  //if (n < 5)
  //	return(OK);
}
int checkcol_checkline(int n)
{
  if (n != 4)
    return (ERROR);
  return (OK);
}

int checksymbol_readtab(char tab[5][5])
{
  int col;
  int line;
  int nbr_diese;
  int nbr_point;

  line = 0;
  col = 0;
  nbr_diese = 0;
  nbr_point = 0;
  while(tab)
    {
      col = 0;
      while (tab[line][col] != '\n' && tab[line][col] != '\0')
	{
	  col++;
	}
      //if (!(checkcol_checkline(col)))
	// return (ERROR);
      line++;
    }
  printf("%d\n", col);
  printf("%d\n", line);
  return (0);
  //if (!(checkcol_checkline(line)))
  // return (ERROR);
  // if ( nbr_diese != 4 || nbr_point != 12)
  //return (ERROR);
  return (OK);
}

int checking_error (void)
{
  char buf [1024];
  int n;
  ssize_t r;
  n = 0;
  r = read(fd, buf, 1024);
	  int funct_check (n)
	  {
		if (r == 0)
		  return (0);
		nbr_diese = 0;
		nbr_point = 0;
		while (n < (n + 20));
		{
		  if (buf[n] == '#')
			nbr_diese++;
		  if (buf[n] == '.')
			nbr_point++;
		  if (buf[n] != '#' && buf[n] != '.' && buf[n] != '\n')
			return (ERROR);
		  n++;
		}
		if (nbr_point != 16)
		  return (ERROR);
		if (nbr_diese != 4)
		  return (ERROR);
		n = n + 20;
	funct_check (n);
	  }
}


