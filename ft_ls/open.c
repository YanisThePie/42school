#include "ft_ls.h"

int main (int argc, char **argv)
{
	(void)argc;
	DIR *dir;
	struct dirent *pdirent;
	char *full_path;
	char *dotslash;

	if (argv[1] == NULL)
		dir = opendir(".");
	else
		dir = opendir(argv[1]);
	if (dir == NULL)
	{
		perror("");
		return(0);
	}
	while((pdirent = readdir(dir)) != NULL)
	{
		full_path = ft_strjoin(argv[1], "/");
		dotslash = ft_strjoin(full_path, pdirent->d_name);
		usestat(dotslash);
	}
	closedir (dir);
}


