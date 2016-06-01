#include "ft_ls.h"

int usestat (char *d_name)
{
	struct stat buf;

	stat(d_name, &buf);
	//ft_putstr((char*)&buf);
	ft_putstr ("last access : ");
	ft_putstr(ctime(&buf.st_atime));
	ft_putstr("last modification : ");
	ft_putnstr(ctime( &buf.st_mtime));
	ft_putchar('\n');
	return(0);
}
