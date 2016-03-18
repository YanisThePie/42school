#include "../get_next_line.h"
#include <stdio.h>

int main (int argc, char **argv)
{
	(void)argv;
	(void)argc;
	char *line;
	int fd = 0;
	int ret;
	
	while((ret = get_next_line(fd, &line)) == 1)
	{
		printf("%s\n", line);
        ft_putnbr(ret);
        ft_putchar('\n');
		ft_strdel(&line);
	}

	while (1);
	return (0);
}
