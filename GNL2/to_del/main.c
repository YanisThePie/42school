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

		ft_putendl("first lecture");
		this = get_next_line(fd, &send);
		ft_putendl(send);
		//ft_putnbr(1);
		ft_putendl("second lecture");
		this = get_next_line(fd, &send);
        ft_putendl(send);
		//ft_putnbr(2);
}
