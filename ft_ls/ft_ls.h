#include "libft/libft.h"
#include <dirent.h>
#include <sys/types.h>
#include <pwd.h>
//#include <uuid/uuid.h>
#include <time.h>
#include <stdio.h>
#include <pwd.h>
#include <grp.h>

int usestat (char *d_name);

typedef struct s_toprint
{
	char	*perm;
	char	*uid;
	char	*gid;
	char	*time;
	char	*name;
	char	*links;
}		t_toprint;


void l_option(char *dotslash);
char *ft_perm (struct stat buf);
void ft_infos (struct stat *buf, char *d_name, struct s_toprint *l_option);
void ft_print_loption(struct s_toprint l_option);
