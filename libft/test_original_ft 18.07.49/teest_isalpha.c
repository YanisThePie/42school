#include <ctype.h>
#include<stdio.h>						 
int ft_isalpha (int c)
{
  if (c >= 65 && c <= 90)
    return (1);

  if (c >= 97 && c <= 122)
    return (1);

  return (0);
}
int main ()
{
  int i;
  int j;
  int a;

  a = '5';
  i = isalpha(a);
  j = ft_isalpha(a);
  printf("%d\n", i);
  printf("%d\n", j);

  return(0);
}
