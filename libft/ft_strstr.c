#include <stdlib.h>
#include <stdio.h>

char *ft_strstr (char *str, char *tofind)
{
  int a;
  int b;
  int c;
  int cpt;
  int cpt2;

  a = 0;
  b = 0;
  c = 0;
  cpt = 0;
  cpt2 = 0;

  while (str[cpt] != '\0')
    {
      if (tofind[cpt2] != str[cpt])
	{
	  cpt++;
	  b++;
	}
      while (tofind[cpt2] == str[cpt])
	{
	  {
	    if (tofind[cpt2] == '\0')
	      {
		return (str + b);
		cpt++;
		cpt2++;
	      }
	  }
	}
    }
  return (0);
}

int main (void)
{
  char *c;
  c = ft_strstr ("michel", "che");
  printf ("%s", c);
}
