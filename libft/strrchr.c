#include <stdio.h>
#include <stdlib.h>
int ft_strlen (char *c)
{
  int cpt;
  
  cpt = 0;
  while (*c != '\0')
    {
      c++;
      cpt++;
    }
  return (cpt);
}
char *ft_strrchr ( char *s, int c)
{
  int i;
  int j;
  int k;
  char *str;
  
  j = ft_strlen (s);
  str = (char*)malloc (sizeof(*s) * j);
  i = 0;
  k = 0;
  while (s)
    {
      while (s[i] != '\0')
	{
	  i++;
	  if (s[i] == c)
	    {
	      str =  (i + s);
	    }
	}
      if (str[k] != '\0')
	return(str);
      else 
	return(0);
    }
  return (0);
}



