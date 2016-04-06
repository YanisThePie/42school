/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 00:05:57 by yismail           #+#    #+#             */
/*   Updated: 2016/04/06 18:47:15 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FDF_H
# define FDF_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "./libft/libft.h"
#include <math.h>
#include <stdio.h>
#include "./minilibx_macos/mlx.h"

typedef struct
{
	int				coord_x;
	int				coord_y;
	int				height;
}					structure;

typedef struct
{
	int xo; 
	int yo;
	int zo;
	int x1;
	int y1;
	int x0;
	int y0;
	int yoo;
}					proj_dots;

typedef struct
{
    int dx;
    int dy;
    int i;
    int xinc;
    int yinc;
    int cumul;
    int x;
	int y;
}                   bresen;

typedef struct
{
    int zoom;
	int alt;
	int move;
	int rotate;
}                   str_cmd;
/*
typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;
*/
int ft_parsing (int argc, char **argv, t_list **list);
void ft_putlist(t_list *elem);
void ligne(proj_dots spc, void *mlx, void *win);//
int ft_window (t_list const *lst);
int ft_pixel_put(t_list const *lst, void *mlx, void *win, str_cmd event);
#endif
