int main (int argc, char **argv)
{
	char *send;
	int fd;
	int i;

	argc = 1;
	i = 0;

	send = NULL;
	fd = open(argv[1], O_RDONLY);

	get_next_line(fd, &send);
	ft_putstr(send);
	get_next_line(fd, &send);
	ft_putstr(send);
	get_next_line(fd, &send);
	ft_putstr(send);
	get_next_line(fd, &send);
	ft_putstr(send);
	get_next_line(fd, &send);
	ft_putstr(send);
	get_next_line(fd, &send);
	ft_putstr(send);
	get_next_line(fd, &send);
	ft_putstr(send);
	get_next_line(fd, &send);
	ft_putstr(send);
	get_next_line(fd, &send);
	ft_putstr(send);
	get_next_line(fd, &send);
	ft_putstr(send);
	get_next_line(fd, &send);
	ft_putstr(send);
	get_next_line(fd, &send);
	ft_putstr(send);
	get_next_line(fd, &send);
	ft_putstr(send);
	get_next_line(fd, &send);
	ft_putstr(send);
	get_next_line(fd, &send);
	ft_putstr(send);
	get_next_line(fd, &send);
	ft_putstr(send);
	return (0);
}
