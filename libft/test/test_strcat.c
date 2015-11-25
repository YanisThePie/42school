#include <string.h>
#include <stdio.h>

int main (void)
{
  char chaine3[] = "bjr";
  char chaine4[] = "msr";

  strcat(chaine3, chaine4);
  printf ("%s", chaine3);
}

