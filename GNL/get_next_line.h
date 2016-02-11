#include "./libft/libft.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define BUFF_SIZE 10000

int get_next_line (int const fd, char **line);
int get_the_buffer(int const fd, char **line, char **membuffer_true, int *j);
char * check_for_new_line (char *str_buf, int *j);
char *keep_str_tmp (char *str, char *str2);
