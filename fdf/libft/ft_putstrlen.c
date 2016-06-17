#include "libft.h"

void ft_putstrlen(char *c, size_t len)
{
	size_t     i;

	i = 0;
	while(c[i] != '\0' && i <= len)
	{
		ft_putchar(c[i]);
		i++;
	}
}
