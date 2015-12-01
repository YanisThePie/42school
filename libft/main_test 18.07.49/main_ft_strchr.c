#include <stdio.h>

int main (void)
{
  char *s;
  char buf [] = "This is a test";

  s = ft_strchr (buf, 't');

  printf ("%s", s);

  return (0);
}

