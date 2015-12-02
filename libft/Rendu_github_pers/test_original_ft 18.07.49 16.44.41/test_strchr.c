#include <stdio.h>
#include <string.h>
int main (void) 
{
  char *s;
  char buf [] = "This is a test";

  s = strchr (buf, 'w');
  
  printf ("%s", s);

  return (0);
}
