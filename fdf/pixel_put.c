/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 00:46:33 by yismail           #+#    #+#             */
/*   Updated: 2016/04/12 08:42:36 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_list const	*lst_pos_max(t_list const *lst)
{
	t_list const	*tmp;
	static int		x_max = 0;
	static int		cpt;
	int				i;

	i = 0;
	cpt = 0;
	tmp = lst;
	while (tmp != NULL && cpt == 0)
	{
		if (x_max < ((structure *)tmp->content)->coord_x)
			x_max = ((((structure *)tmp->content)->coord_x));
		tmp = tmp->next;
	}
	tmp = lst;
	while (tmp != NULL && i <= x_max)
	{
		i++;
		tmp = tmp->next;
	}
	cpt++;
	return (tmp);
}

int				ft_pixel_put_v(t_list const *lst,
								void *mlx, void *win, proj_dots *spc)
{
	t_list const	*tmp;

	tmp = lst_pos_max(lst);
	spc->x0 = spc->x1; // reprend la valeur du point h
	spc->y0 = spc->y1; // idem
	if (tmp != NULL)
	{
		spc->xo = ((structure *)tmp->content)->coord_x;
		spc->yo = ((structure *)tmp->content)->coord_y;
		spc->zo = ((structure *)tmp->content)->height + ((((structure *)tmp->content)->height > 0) ? spc->event.alt : 0);
	}
	spc->x1 = ((0.71) * (spc->xo - spc->yo) * (spc->event.zoom + 20));
	spc->y1 = ((((0.41) * (spc->xo + spc->yo) + 0.82 * -spc->zo) * (spc->event.zoom + 20)) + (4 * spc->event.move_y)) * (0.25 * spc->event.rotate_y);
	spc->x1 += 500;
	spc->y1 += 180;
	spc->color_act = colors(spc->zo, spc);
	if (tmp && tmp->next != NULL)
		spc->color_next = colors(((structure *)tmp->next->content)->height, spc);
	else
		spc->color_next = 0x878787;
	if (spc->y0 != 0 && spc->x0 != 0)
		ligne(*spc, mlx, win);
	return(0);
}

int				ft_pixel_put_h(t_list const *tmp, void *mlx, void *win, proj_dots *spc)
{
	t_list const	*lst;

	lst = tmp;
	spc->xo = ((structure *)lst->content)->coord_x;
	spc->yo = ((structure *)lst->content)->coord_y;
	spc->zo = ((structure *)lst->content)->height + ((((structure *)tmp->content)->height > 0) ? spc->event.alt : 0);
	spc->x1 = (((0.71) * (spc->xo - spc->yo) * (spc->event.zoom + 20)));
	spc->y1 = (((0.41) * (spc->xo + spc->yo) + 0.82 * -spc->zo) * (spc->event.zoom + 20) + (4 * spc->event.move_y)) * (0.25 * spc->event.rotate_y);
	spc->x1 += 500;
	spc->y1 += 180;
	spc->color_act = colors(spc->zo, spc);
    if (tmp && tmp->next != NULL)
		spc->color_next = colors(((structure *)lst->next->content)->height, spc);
	else
		spc->color_next= 0x878787;
	if (spc->y0 != 0 && spc->x0 != 0 && spc->yoo == spc->yo)
		ligne(*spc, mlx, win);
	spc->x0 = spc->x1;
	spc->y0 = spc->y1;
	spc->yoo = spc->yo;
	spc->zoo = spc->zo;
	return (0);
}

void z_max_min(t_list const *tmp, proj_dots *spc)
{
	t_list const *lst;

	lst = tmp;

	while (lst != NULL)
	{
		if ((((structure *)lst->content)->height) > spc->event.z_max)
			spc->event.z_max = (((structure *)lst->content)->height);
		if ((((structure *)lst->content)->height) < spc->event.z_min)
			spc->event.z_min = (((structure *)lst->content)->height);
		lst = lst->next;
	}
}

t_list const *change_alt(t_list const *tmp, proj_dots *spc)
{
	t_list  const *first;

	(void)spc;
	first = tmp;
	while (tmp != NULL)
    {
		if ((((structure *)tmp->content)->height) > 0)
			(((structure *)tmp->content)->height) = ((((structure *)tmp->content)->height));// + spc->event.alt;
        tmp = tmp->next;
    }
	return (first);
}

int				ft_pixel_put(t_list const *lst, void *mlx, 
							void *win, proj_dots env)
{
	proj_dots		spc;
	t_list const	*tmp;

	spc = env;
	tmp = lst;
	spc.x0 = 0;
	spc.y0 = 0;
	spc.yoo = 0;
	spc.zoo = 0;
	z_max_min(tmp, &spc);
	tmp = change_alt(tmp, &spc);
	while (tmp != NULL)
	{
		ft_pixel_put_h(tmp, mlx, win, &spc);
		spc.zoo = spc.zo;
		ft_pixel_put_v(tmp, mlx, win, &spc);
		tmp = tmp->next;
	}
	return (0);
}
