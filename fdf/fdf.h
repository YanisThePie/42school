/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 00:05:57 by yismail           #+#    #+#             */
/*   Updated: 2016/04/12 12:57:47 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "./libft/libft.h"
# include <math.h>
# include <unistd.h> 
# include "./minilibx_macos/mlx.h"

typedef	struct		s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;

typedef	struct		s_stru
{
	int				coord_x;
	int				coord_y;
	int				height;
}					t_stru;

typedef	struct		s_strcmd
{
	int				zoom;
	int				alt;
	int				move_y;
	int				move_x;
	int				rotate_y;
	int				z_min;
	int				z_max;
}					t_strcmd;
typedef	struct		s_projdots
{
	int				xo;
	int				yo;
	int				zo;
	int				x1;
	int				y1;
	int				x0;
	int				y0;
	int				yoo;
	int				zoo;
	int				t_color_act;
	int				t_color_next;
	t_strcmd		event;
	void			*mlx;
	void			*win;
	t_list	const	*tmp;
}					t_projdots;

typedef	struct		s_bresen
{
	int				dx;
	int				dy;
	int				i;
	int				xinc;
	int				yinc;
	int				cumul;
	int				x;
	int				y;
}					t_bresen;

int					ft_parsing (int argc, char **argv, t_list **list);
void				ft_putlist(t_list *elem);
void				ligne(t_projdots spc, void *mlx, void *win);
int					ft_window (t_list const *lst);
int					ft_pixel_put(t_list const *lst, void *mlx,
					void *win, t_projdots env);
int					colors (int zo, t_projdots *spc);
int					my_key_funct(int keycode, t_projdots *spc);
void				ft_set_event(t_projdots *env);
int					color_to_int(t_color c);
t_list const		*change_alt(t_list const *tmp);
#endif
