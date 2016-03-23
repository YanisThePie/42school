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
		xn = 4 * xo + 4 * yo + 1 * zo;
		yn = 2 * xo - 4 * yo - 4 * zo;
		xn += 20;
		yn += 500;
		if (yno != 0)
		{
			//ytemp = yno;
			while (yno <= yn)
			{
				mlx_pixel_put(mlx, win, yno, xn, 0x00ffffff);
				yno++;
				//xno++;
			}
		}
		mlx_pixel_put(mlx, win, yn, xn, 0x00ffffff);
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

