#include "./libft/libft.h"
#include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

int get_next_line (int const fd, char **line);
int get_the_buffer(int const fd, char **line, char **membuffer_true, int *j);
char * check_for_new_line (char *str_buf, int *j);
char *keep_str_tmp (char *str, char *str2);