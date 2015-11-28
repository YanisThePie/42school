#include <stdlib.h>
int ft_strlen (char *c)
{
	int cpt;
  
	cpt = 0;
	while (c[cpt])
    {
		cpt++;
    }
	return (cpt);
}

char *ft_strdup(char *str)
{
	int j;
	int i;
	char *cpy;
	
	i = 0;
	j = ft_strlen (str);
	cpy = (char *) malloc(j * sizeof(*str));
	while (i < j && str[i] != '\0')
	{	
		cpy[i] = str[i];
		i++;
	}
	return (cpy);
}
