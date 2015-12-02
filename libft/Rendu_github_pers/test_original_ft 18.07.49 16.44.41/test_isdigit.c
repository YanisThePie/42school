#include <stdio.h>
#include <ctype.h>

int ft_isdigit (int c)
{
  if (c >= 48 && c <= 57)
    return (1);

  return (0);
}
int main ()
{
  int i;
  int j;
  int a;
  
  a = 'f';
  i = isdigit(a);
  j = ft_isdigit(a);
  printf("%d\n", i);
  printf("%d\n", j);

  return(0);
}
