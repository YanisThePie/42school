#include <stdio.h>
#include <stdlib.h>

int main (void)
{
  char *s;
  char buf [] = "this is a test";

  s = ft_strrchr (buf, '8');

  printf ("%s", s);

  return (0);
}
