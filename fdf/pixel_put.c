#include "fdf.h"

t_list const *lst_pos_max (t_list const *lst)
{
	t_list const *tmp;
	static int x_max = 0;
	static int cpt;
	int i;

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

int ft_pixel_put_v(t_list const *lst, proj_dots spc, void *mlx, void *win, str_cmd event)
{
	t_list const        *tmp;
	int i;

	i = 0;
	tmp = lst_pos_max(lst);
	spc.x0 = spc.x1;
	spc.y0 = spc.y1;
	if (tmp != NULL)
	{
		spc.xo = ((structure *)tmp->content)->coord_x;
		spc.yo = ((structure *)tmp->content)->coord_y;
		spc.zo = ((structure *)tmp->content)->height;
	}
	spc.x1 = ((0.71) * (spc.xo - spc.yo) * 20);
	spc.y1 = (((0.41) * (spc.xo + spc.yo) + 0.82 * -spc.zo) * (event.zoom *20));
	spc.x1 += 500;
	spc.y1 += 180;
	if (spc.y0 != 0 && spc.x0 != 0)
		ligne(spc, mlx, win);
	return(0);
}

int ft_pixel_put_h (t_list const *lst, void *mlx, void *win, str_cmd event)
{
	proj_dots spc;
	int yoo;

	spc.x0 = 0;
	spc.y0 = 0;
	yoo = 0;
	while ((lst = lst->next) != NULL)
	{

		spc.xo = ((structure *)lst->content)->coord_x;
		spc.yo = ((structure *)lst->content)->coord_y;
		spc.zo = ((structure *)lst->content)->height;
		spc.x1 = (((0.71) * (spc.xo - spc.yo) * 20));
		spc.y1 = (((0.41) * (spc.xo + spc.yo) + 0.82 * -spc.zo) * (event.zoom * 20));
		spc.x1 += 500;
		spc.y1 += 180;
		if (spc.y0 != 0 && spc.x0 != 0 && yoo == spc.yo)
			ligne(spc, mlx, win);
		ft_pixel_put_v(lst, spc, mlx, win, event);
		spc.x0 = spc.x1;
		spc.y0 = spc.y1;
		yoo = spc.yo;
	}
	return (0);
}
