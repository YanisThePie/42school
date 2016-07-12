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
	char	*size;
}		t_toprint;

typedef struct s_env
{
	DIR *dir;
	char *dotslash;
	struct dirent *pdirent;
	char		**argv;

}				t_env;

void l_option(char *d_name, struct stat *buf);
void ft_perm (struct stat *buf, struct s_toprint *l_option);
void ft_infos (struct stat *buf, struct s_toprint *l_option);
void ft_print_loption(struct s_toprint l_option);
void print_simple_option (char *d_name);
int read_the_path(char *path, char *option, struct s_env env);
int choose_opt(char *dotslash, char *option,struct s_env env);
int no_arg(struct s_env *env);
int how_many_flags (char **argv, struct s_env *env);
void ft_print_soption(struct s_toprint *s_option);
