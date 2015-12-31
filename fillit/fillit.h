/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaustry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 17:30:32 by jaustry           #+#    #+#             */
/*   Updated: 2015/12/30 17:31:00 by jaustry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUF_SIZE 1

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "../libft/libft.h"
# include <stdio.h>
# define ERROR { printf("Error in %s, at line %d\n", __FILE__, __LINE__); exit(EXIT_FAILURE); }

typedef struct	dlist
{
  void		*content;
  size_t	content_size;
  struct dlist	*prev;
  struct dlist *next;
}		d_list;

int		get_pieces(int fd);
void		verify_piece(char *buf);
void		verify_n(char *buf);
void		verify_link(char *buf);

#endif
