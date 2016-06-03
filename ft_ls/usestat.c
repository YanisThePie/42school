#include "ft_ls.h"

int usestat (char *d_name)
{
	struct stat buf;
	struct passwd *pw;
	struct group *gr;
	char *perm_buffer;

	lstat(d_name, &buf);
	//ft_putstr((char*)&buf);
	ft_putstr("last modification : ");
	ft_putnstr((ctime(&buf.st_atime) + 3));
	perm_buffer = malloc(sizeof(char) *10);
	perm_buffer[0] = buf.st_mode & S_IFREG ? '-' : (buf.st_mode & S_IFDIR ? 'd' : '#');
	perm_buffer[1] = buf.st_mode & S_IRUSR ? 'r' : '-';
	perm_buffer[2] = buf.st_mode & S_IWUSR ? 'w' : '-';
	perm_buffer[3] = buf.st_mode & S_IXUSR ? 'x' : '-';
	perm_buffer[4] = buf.st_mode & S_IRGRP ? 'r' : '-';
	perm_buffer[5] = buf.st_mode & S_IWGRP ? 'w' : '-';
	perm_buffer[6] = buf.st_mode & S_IXGRP ? 'x' : '-';
	perm_buffer[7] = buf.st_mode & S_IROTH ? 'r' : '-';
	perm_buffer[8] = buf.st_mode & S_IWOTH ? 'w' : '-';
	perm_buffer[9] = buf.st_mode & S_IXOTH ? 'x' : '-';
	perm_buffer[10] = '\0';
	ft_putnstr(perm_buffer);
	pw = getpwuid(buf.st_uid);
	gr = getgrgid(buf.st_gid);

	if (pw != 0)
		ft_putnstr(pw->pw_name);
	if (gr != 0)
		ft_putnstr(gr->gr_name);
	ft_putchar('\n');
	free(perm_buffer);
	return(0);
}
