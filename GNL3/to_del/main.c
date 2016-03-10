#include "../get_next_line.h"

int main (int argc, char **argv)
{
		char *send;
		int fd;
		int i;
		int ret;

		argc = 1;
		i = 0;

		send = NULL;
		fd = open(argv[1], O_RDONLY);

		ret = get_next_line (fd, &send);
		ft_putendl(send);
		free(send);
		ft_putnbr(ret);
		//get_next_line (fd, &send);
        //ft_putendl(send);
		//get_next_line (fd, &send);
        //ft_putendl(send);
}
