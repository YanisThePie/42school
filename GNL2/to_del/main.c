#include "../get_next_line.h"

int main (int argc, char **argv)
{
		char *send;
		int fd;
		int i;
		int this;

		argc = 1;
		i = 0;

		send = NULL;
		fd = open(argv[1], O_RDONLY);

		while((this = get_next_line(fd, &send)))
		{
			ft_putnbr(this);
			ft_putchar('\n');
			ft_putstr(send);
			free(send);
			send = NULL;
			i++;
		}
		ft_putnbr(this);
}
