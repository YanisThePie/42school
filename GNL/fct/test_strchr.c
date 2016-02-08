#include "get_next_line.h"

char*ft_strchr(char*s, int c);

int main (void)
{
	char *str;
	
	str = ft_strchr("bonjour", 'n');
	ft_putstr(str);
	return(0);
}
