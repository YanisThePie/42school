#include "ft_ls.h"

int main (int argc, char **argv)
{
	(void)argc;
	DIR *dir;
	struct dirent *pdirent;

	dir = opendir(argv[1]);
	if (dir == NULL)
	{
		ft_putstr("cannot open directory");
		return(0);
	}
	while ((pdirent = readdir(dir)) != NULL)
	{
		ft_putnstr(pdirent->d_name);
		usestat(pdirent->d_name);
	}
	closedir (dir);
}


