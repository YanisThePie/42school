#include "ft_ls.h"

int main (int argc, char **argv)
{
	(void)argc;
	DIR *dir;
	struct dirent *pdirent;

	if (argv[1] == NULL)
		dir = opendir(".");
	else
		dir = opendir(argv[1]);

	if (dir == NULL)
	{
		perror("");
		return(0);
	}
	while ((pdirent = readdir(dir)) != NULL)
	{
		ft_putnstr(pdirent->d_name);
		usestat(pdirent->d_name);
	}
	closedir (dir);
}


