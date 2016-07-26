#include "libft.h"
char **tab_realloc(char **tab)
{
	int		j;
	int		i;
	char	**tab2;

	i = 0;
	j = 0;
	while (tab[i])
		i++;
	tab2 = (char **)malloc(sizeof(*tab2) * (i + 1));
	while (j <= i)
	{
		tab2[j] = ft_strdup(tab[j]);
		j++;
	}
	return (tab2);
}