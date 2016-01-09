#include "./libft/libft.h"
#include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

typedef struct	s_gnl {
	char		*s;
	int			fd;
}				t_gnl;

t_list	*ptr;


ptr = malloc(sizeof(t_list));

ptr->content_size = sizeof(struct s_gnl);
ptr->content = malloc(ptr->content_size);
ptr->next = NULL;

((t_gnl *)ptr->content)->fd = fd;
((t_gnl *)ptr->content)->s = "rien";
