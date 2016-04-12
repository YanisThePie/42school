/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 00:05:57 by yismail           #+#    #+#             */
/*   Updated: 2016/04/12 04:52:41 by yismail          ###   ########.fr       */
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
    int             r;
    int             g;
    int             b;
}                   color;

typedef struct
{
	int				coord_x;
	int				coord_y;
	int				height;
}					structure;

typedef struct
{
    int zoom;
    int alt;
    int move_y;
	int move_x;
    int rotate_y;
	int z_min;
	int z_max;
}                   str_cmd;
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
	int zoo;
	int color_act;
	int color_next;
	str_cmd event;
	void	*mlx;
	void	*win;
	t_list	const *tmp;
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

/*
typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;
*/
int		ft_parsing (int argc, char **argv, t_list **list);
void	ft_putlist(t_list *elem);
void	ligne(proj_dots spc, void *mlx, void *win);//
int		ft_window (t_list const *lst);
int		ft_pixel_put(t_list const *lst, void *mlx, void *win, proj_dots env);
int		colors (int zo, proj_dots *spc);
int     my_key_funct(int keycode, proj_dots *spc);
void    ft_set_event(proj_dots *env);
int		color_to_int(color c);
#endif
