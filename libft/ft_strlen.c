int ft_strlen (char *c)
{
  int cpt;
  
  cpt = 0;
  while (*c != '\0')
    {
      c++;
      cpt++;
    }
  return (cpt);
}
