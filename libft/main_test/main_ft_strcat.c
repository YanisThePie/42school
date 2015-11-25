#include <stdio.h>

int main (void)
{
  char dest[50] = "bonjur";
  char src[50] = "ses";

  ft_strcat (dest, src);
  printf ("%s", dest);
}
