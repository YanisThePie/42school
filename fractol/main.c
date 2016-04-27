#include "fractol.h"

int mouse_pos(int x, int y)
{
	ft_putstr("x: ");
	ft_putnbr(x);
	ft_putchar('\n');
	ft_putstr("y: ");
	ft_putnbr(y);
	ft_putchar('\n');
	ft_putchar('\n');
	return(0);
}

int ft_window()
{
	t_env env;

	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, 1200, 1200, "fractol");
	env.img = mlx_new_image(env.mlx, 1000, 1000);
	env.data = mlx_get_data_addr(env.img, &env.bpp, &env.sizeline, &env.endian);
	mandelbrot(&env);
	mlx_put_image_to_window(env.mlx, env.win, env.img, 50, 50);
    mlx_hook(env.win, 6, 0 ,mouse_pos, &env);
	//mlx_mouse_hook(env.win, mouse_click, &env);
	mlx_loop(env.mlx);
	return (0);
}


int main (int argc, char **argv)
{
	(void)*argv;
	if (argc != 2)
		exit(EXIT_FAILURE);
	ft_window();
	return (0);
}
