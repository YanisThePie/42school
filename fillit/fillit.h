/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaustry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 17:30:32 by jaustry           #+#    #+#             */
/*   Updated: 2016/01/06 18:24:25 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUF_SIZE 1

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "./libft/libft.h"
# include <stdio.h>
# define ERROR { printf("Error in %s, at line %d\n", __FILE__, __LINE__); exit(EXIT_FAILURE); }


typedef struct	s_dlist
{
  char			**content;
  size_t		content_size;
  struct s_dlist	*prev;
  struct s_dlist	*next;
}				t_dlist;

t_dlist			*get_pieces(int fd);
void		verify_piece(char *buf);
int         print_tab (char **tab);
t_dlist     *ft_dlstnew(char **content, size_t content_size);
char        **take (char *buf, char alpha);
char         **main_creation (char *buffer, char alpha);

void		verify_n(char *buf);
void		verify_link(char *buf);
int 		print_tab (char **tab);
void create_list (char **tab);
void 		create_list (char **tab);
char 		**create_tab_bis(char *piece, char e);


#endif
