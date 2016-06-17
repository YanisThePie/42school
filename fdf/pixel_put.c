/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 00:46:33 by yismail           #+#    #+#             */
/*   Updated: 2016/04/24 16:52:07 by yismail          ###   ########.fr       */
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
		if (x_max < ((t_stru *)tmp->content)->coord_x)
			x_max = ((((t_stru *)tmp->content)->coord_x));
		tmp = tmp->next;
	}
	tmp = lst;
	while (tmp != NULL && i <= x_max)
	{
		i++;
		tmp = tmp->next;
		if (tmp != NULL && ((t_stru *)tmp->content)->coord_x
		== (((t_stru *)lst->content)->coord_x))
			return (tmp);
	}
	cpt++;
	return (lst);
}

int				ft_pixel_put_v(t_list const *lst,
								void *mlx, void *win, t_projdots *spc)
{
	t_list const	*tmp;

	tmp = lst_pos_max(lst);
	spc->x0 = spc->x1;
	spc->y0 = spc->y1;
	if (tmp != NULL)
	{
		spc->xo = ((t_stru *)tmp->content)->coord_x;
		spc->yo = ((t_stru *)tmp->content)->coord_y;
		spc->zo = ((t_stru *)tmp->content)->height +
		((((t_stru *)tmp->content)->height > 0) ? spc->event.alt : 0);
	}
	spc->x1 = ((0.71) * (spc->xo - spc->yo) * (spc->
	event.zoom + 20)) + (4 * spc->event.move_x);
	spc->y1 = ((((0.41) * (spc->xo + spc->yo) + 0.82 * -spc->zo) * (spc->
	event.zoom + 20)) + (4 * spc->event.move_y)) * (0.25 * spc->event.rotate_y);
	(spc->x1 += 500);
	(spc->y1 += 180);
	spc->t_color_act = colors(spc->zo, spc);
	if (tmp && tmp->next != NULL)
		spc->t_color_next = colors(((t_stru *)tmp->next->content)->height, spc);
	else
		spc->t_color_next = 0xA83044;
	if (spc->y0 != 0 && spc->x0 != 0)
		ligne(*spc, mlx, win);
	return (0);
}

int				ft_pixel_put_h(t_list const *tmp, void *mlx,
				void *win, t_projdots *spc)
{
	t_list const	*lst;

	lst = tmp;
	spc->xo = ((t_stru *)lst->content)->coord_x;
	spc->yo = ((t_stru *)lst->content)->coord_y;
	spc->zo = ((t_stru *)lst->content)->height +
	((((t_stru *)tmp->content)->height > 0) ? spc->event.alt : 0);
	spc->x1 = (((0.71) * (spc->xo - spc->yo) * (spc->
	event.zoom + 20)) + (4 * spc->event.move_x));
	spc->y1 = (((0.41) * (spc->xo + spc->yo) + 0.82 * -spc->zo) * (spc->
	event.zoom + 20) + (4 * spc->event.move_y)) * (0.25 * spc->event.rotate_y);
	spc->x1 += 500;
	spc->y1 += 180;
	spc->t_color_act = colors(spc->zo, spc);
	if (tmp && tmp->next != NULL)
		spc->t_color_next = colors(((t_stru *)lst->next->content)->height, spc);
	else
		spc->t_color_next = 0xA83044;
	if (spc->y0 != 0 && spc->x0 != 0 && spc->yoo == spc->yo)
		ligne(*spc, mlx, win);
	spc->x0 = spc->x1;
	spc->y0 = spc->y1;
	spc->yoo = spc->yo;
	spc->zoo = spc->zo;
	return (0);
}

void			z_max_min(t_list const *tmp, t_projdots *spc)
{
	t_list const *lst;

	lst = tmp;
	while (lst != NULL)
	{
		if ((((t_stru *)lst->content)->height) > spc->event.z_max)
			spc->event.z_max = (((t_stru *)lst->content)->height);
		if ((((t_stru *)lst->content)->height) < spc->event.z_min)
			spc->event.z_min = (((t_stru *)lst->content)->height);
		lst = lst->next;
	}
}

int				ft_pixel_put(t_list const *lst, void *mlx,
							void *win, t_projdots env)
{
	t_projdots		spc;
	t_list const	*tmp;

	spc = env;
	tmp = lst;
	spc.x0 = 0;
	spc.y0 = 0;
	spc.yoo = 0;
	spc.zoo = 0;
	z_max_min(tmp, &spc);
	tmp = change_alt(tmp);
	while (tmp != NULL)
	{
		ft_pixel_put_h(tmp, mlx, win, &spc);
		spc.zoo = spc.zo;
		ft_pixel_put_v(tmp, mlx, win, &spc);
		tmp = tmp->next;
	}
	return (0);
}
