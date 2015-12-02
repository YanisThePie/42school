#include <string.h>
#include <stdio.h>

int main (void)
{
  char dest[9] = "bdddddnjur";
  char src[50] = "sesdddd";

  strcat (dest, src);
  printf ("%s", dest);


}

