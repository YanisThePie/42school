#include <stdlib.h>
#include <stdio.h>

int ft_strlen (char *str)
{
  int nbr;
  
  nbr = 0;
  while (str[nbr] != '\0')
    nbr++;

  return (nbr);
}

char *ft_strcat (char *dest, char *src)
{ 
  int a;
  int b;
  char *temp;

  a = ft_strlen (dest);
  b = ft_strlen (src);

  temp = malloc(sizeof(char)*(a+b));
  a = 0;
  b = 0;

    while (dest[a] != '\0')
      {
	temp[a] = dest[a];
	a++;
      }
  while (src[b] != '\0')
    {
      temp[a] = src[b];
      a++;
      b++;
    }
  b = 0;
  dest = malloc (sizeof (char)*a);
  
  while (temp[b] != '\0')
    {
      dest[b] = temp[b];
      b++;
    }
  free (temp);
  return(dest);
}


int main (void)
{
    char chaine3[] = "bjr";
    char chaine4[] = "msr";
    
   ft_strcat(chaine3, chaine4);
    printf ("%s", chaine3);
}

