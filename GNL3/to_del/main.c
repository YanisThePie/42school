#include "../get_next_line.h"
#include <stdio.h>

int main (int argc, char **argv)
{
	(void)argv;
	(void)argc;
	char *line;
	int fd = 0;
	
	while(get_next_line(fd, &line) == 1)
	{
		printf("%s\n", line);
		ft_strdel(&line);
	}
	return (0);
}
