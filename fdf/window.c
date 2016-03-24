#include "./libft/libft.h"
#include "./minilibx_macos/mlx.h"
#include "fdf.h"
int my_key_funct(int keycode, void *param)
{
	(void)param;
	ft_putstr("the key is ");
	ft_putnbr(keycode);
	ft_putchar('\n');
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	return(0);
}

void ft_bresenham(int x0, int y0, int x1, int y1, void *mlx, void *win)
{
	int dx;
	int dy;
	int sx;
	int sy;
	int err;
	int e2;

	dx = abs(x1-x0);
	dy = abs(y1-y0);
	sx = x0 < x1 ? 1 : -1;
	sy = y0 < y1 ? 1 : -1;
	err = (dx > dy ? dx : -dy) / 2;
	while (x0 <= x1 && y0 <= y1)
	{
		mlx_pixel_put(mlx, win, x0, y0, 0x00ffffff);
		e2 = err;
		if (e2 > -dx)
		{	
			err -= dy;
			x0 += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			y0 += sy;
		}
	}
}
int ft_pixel_put (t_list const *tmp, void *mlx, void *win)
{
	int xo,yo,zo, xn,yn, xno, yno;

	xno = 0;
	yno = 0;
	while ((tmp = tmp->next) != NULL)
	{

		xo = ((structure *)tmp->content)->coord_x;
		yo = ((structure *)tmp->content)->coord_y;
		zo = ((structure *)tmp->content)->height;
		xn = 16 * xo + 16 * yo + 4 * zo;
		yn = 8 * xo - 16 * yo - 16 * zo;
		xn += 20;
		yn += 500;
		if (yno != 0 && xno != 0)
			ft_bresenham(yno, xno, yn, xn, mlx, win);
		if (yno != 0 && xno != 0)
            ft_bresenham(yno, xno, yn, xn, mlx, win);
		xno = xn;
		yno = yn;
	}
	return (0);
}


int ft_window (t_list const *lst)
{
	void	*mlx;
	void	*win;
	t_list const *tmp;
	
	mlx = mlx_init ();
	win = mlx_new_window(mlx, 1200, 1200, "mlx 42");
	tmp = lst;
	ft_pixel_put(tmp, mlx, win);
	mlx_key_hook(win, my_key_funct, 0);
	mlx_loop(mlx);
	return(0);
}

