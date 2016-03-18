#include "./libft/libft.h"
#include "./minilibx_macos/mlx.h"

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

int ft_pixel_put ()
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	
	mlx = mlx_init ();
	win = mlx_new_window(mlx, 600, 600, "mlx 42");
	x = 50;
	while (y < 300)
	{
		y = 50;
		while (x < 300)
		{
			mlx_pixel_put(mlx, win, y, x, 0x00FFFFFF);
			x++;
		}
		y++;
	}
	mlx_key_hook(win, my_key_funct, 0);
	mlx_loop(mlx);
	return(0);
}

