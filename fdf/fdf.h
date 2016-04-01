/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 00:05:57 by yismail           #+#    #+#             */
/*   Updated: 2016/03/22 19:59:09 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FDF_H
# define FDF_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "./libft/libft.h"
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
}					proj_dots;

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
int ft_window (t_list const *lst);
int ft_pixel_put_h (t_list const *lst, void *mlx, void *win);
#endif
