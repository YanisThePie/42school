#include "libft.h"

void ft_putnstr(char *c)
{
	int		i;

	i = 0;
	while(c[i] != '\0')
	{
		ft_putchar(c[i]);
		i++;
	}
	ft_putchar('\n');
}
