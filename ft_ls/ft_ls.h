#include "libft/libft.h"
#include <dirent.h>
#include <sys/types.h>
#include <pwd.h>
#include <uuid/uuid.h>
#include <time.h>
#include <stdio.h>
#include <pwd.h>
#include <grp.h>

int usestat (char *d_name);

typedef struct s_toprint
{
	char	perm[10];
	char	*uid;
	char	*gid;
	char	*time;
	char	*name;
}		t_toprint;
