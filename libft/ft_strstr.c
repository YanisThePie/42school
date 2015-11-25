char *ft_strstr (char *str, char *tofind)
{
  int a;
  int b;
  int c;
  int cpt;
  int cpt2;

  a = 0;
  b = 0;
  c = 0;
  cpt = 0;
  cpt2 = 0;

  while (str[cpt] != '\0')
    {
      if (tofind[cpt2] != str[cpt])
	{
	  cpt++;
	  b++;
	}
      while (tofind[cpt2] == str[cpt])
	{
	  cpt2++;
	  cpt++;
	  if (tofind[cpt2] == '\0')
	    {
	      return (str + b);
	    }
	}
    }
  return (0);
}