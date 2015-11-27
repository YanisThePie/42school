/*(header)*/

int ft_strcmp(char *s1, char *s2)
{
  int i;
  int j;
  
  i = 0;
  j = 0;
  while (s1[i] == s2[i] && s1[i])
    i++;
  j = (s1[i] - s2[i]);
  return (j);
}
