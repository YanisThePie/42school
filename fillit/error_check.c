#define OK 1
#define ERROR 0
#include <stdio.h>
int checksides(char **tab)
{
  int col;
  int line;

  col = 0;
  line = 0;
  while (tab[line][col] != '\0')
    {
      col = 0;
      while (tab[line][col] != '\n')
	{
	  if (tab[line][col] == '#')
	    { 
	      if (tab[line + 1][col] != '#' && tab[line][col +1] != '#'
		  && tab[line - 1][col] != '#' && tab[line][col - 1] != '#')
		return (ERROR);
	    }
	  col++;
	}
      line++;
    }
  return(OK);
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
  while(tab[line][col] != '\0')
    {
      col = 0;
      while (tab[line][col] != '\n' && tab[line][col] != '\0')
	{
	  if (tab[line][col] == '#')
	    nbr_diese++;
	  if (tab[line][col] == '.')
	    nbr_point++;
	  // if (tab[line][col] != '#' && tab[line][col] != '.')
	  //return(ERROR);
	  col++;
	}
      //if (!(checkcol_checkline(col)))
	// return (ERROR);
      line++;
    }
  printf("%d\n", col);
  printf("%d\n", line);
  //if (!(checkcol_checkline(line)))
  // return (ERROR);
  if ( nbr_diese != 4 || nbr_point != 12)
  return (ERROR);
  return (OK);
}

int main (void)
{

  char tab[5][5] = 
    {{ '.', '.', '#', '.'},
     { '.', '.', '#', '.'},
     { '.', '.', '#', '.'},
     { '.', '.', '#', '.'}};
  if (!(checksymbol_readtab(tab)))
  {
    printf("non\n");
    return(0);
  }
  printf("ok\n");
  return(0);
}
