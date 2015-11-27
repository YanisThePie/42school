#include <stdio.h>

int main (void)
{
  int i;
  char s1[50] = "yolow";
  char s2[50] = "yoloz";

  i = ft_strcmp (s1, s2);

  printf ("%d", i);
}
