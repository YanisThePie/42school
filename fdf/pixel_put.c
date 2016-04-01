#include "fdf.h"

void ft_bresenham(proj_dots spc, void *mlx, void *win)
{
	int dx;
	int dy;
	int sx;
	int sy;
	int err;
	int e2;

	dx = abs(spc.x1-spc.x0);
	dy = abs(spc.y1-spc.y0);
	sx = spc.x0 < spc.x1 ? 1 : -1;
	sy = spc.y0 < spc.y1 ? 1 : -1;
	err = (dx > dy ? dx : -dy) / 2;
	while (spc.x0 <= spc.x1 && spc.y0 <= spc.y1)
	{
		mlx_pixel_put(mlx, win, spc.x0, spc.y0, 0x00ffffff);
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			spc.x0 += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			spc.y0 += sy;
		}
	}
}

int ft_pixel_put_v(t_list const *lst, proj_dots spc, void *mlx, void *win)
{
	t_list const        *tmp;
	static int          x_max = 0;
	static int          y_max = 0;
	static int          cpt = 0;
	int                 i   = 0;

	tmp = lst;
	while (tmp != NULL && cpt == 0)
	{
		if (x_max < ((structure *)tmp->content)->coord_x)
			x_max = ((((structure *)tmp->content)->coord_x));
		if (y_max < ((structure *)tmp->content)->coord_y)
			y_max = ((((structure *)tmp->content)->coord_y));
		tmp = tmp->next;
	}
	tmp = lst;
	while (tmp != NULL && i <= x_max)
	{
		i++;
		tmp = tmp->next;
	}
	spc.x0 = spc.x1;
	spc.y0 = spc.y1;
	if (tmp != NULL)
	{
		spc.xo = ((structure *)tmp->content)->coord_x;
		spc.yo = ((structure *)tmp->content)->coord_y;
		spc.zo = ((structure *)tmp->content)->height;
	}
	spc.y1 = 16 * spc.xo + 16 * spc.yo + 4 * spc.zo;
	spc.x1 = 8 * spc.xo - 16 * spc.yo - 16 * spc.zo;
	spc.x1 += 500;
	spc.y1 += 50;
	if (spc.y0 != 0 && spc.x0 != 0)
		ft_bresenham(spc, mlx, win);
	cpt++;
	return(0);
}

int ft_pixel_put_h (t_list const *lst, void *mlx, void *win)
{
	proj_dots spc;

	spc.x0 = 0;
	spc.y0 = 0;
	while ((lst = lst->next) != NULL)
	{

		spc.xo = ((structure *)lst->content)->coord_x;
		spc.yo = ((structure *)lst->content)->coord_y;
		spc.zo = ((structure *)lst->content)->height;
		spc.y1 = 16 * spc.xo + 16 * spc.yo + 4 * spc.zo;
		spc.x1 = 8 * spc.xo - 16 * spc.yo - 16 * spc.zo;
		spc.x1 += 500;
		spc.y1 += 50;
		if (spc.y0 != 0 && spc.x0 != 0)
			ft_bresenham(spc, mlx, win);
		ft_pixel_put_v(lst, spc, mlx, win);
		spc.x0 = spc.x1;
		spc.y0 = spc.y1;
	}
	return (0);
}
