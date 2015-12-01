#include <stddef.h>
#include <stdio.h>

int main (void)
{
  int i;
  char s1[50] = "yoloa";
  char s2[50] = "yoloz";

  i = ft_strncmp (s1, s2, 5);

  printf ("%d", i);
}
