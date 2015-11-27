#include <string.h>
#include <stdio.h>

int main (void)
{
  int i;
  char s1[50] = "yolow";
  char s2[50] = "yoloz";

  i = strncmp (s1, s2, 0);

  printf ("%d", i); 
}
