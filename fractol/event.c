#include "fractol.h"

void ft_new_img(t_env *env)
{
	if (!env->img)
	{
		env->img = mlx_new_image(env->mlx, env->set.img_x, env->set.img_y);
		env->data = mlx_get_data_addr(env->img, &(env->bpp), &(env->sizeline), &(env->endian));
	}
	else
	{
		//mlx_destroy_image(env->mlx, env->img);
		ft_bzero(env->data, 4 * 1200 * 1200);
		//env->img = mlx_new_image(env->mlx, env->setup.img_x, env->setup.img_y);
		//env->data = mlx_get_data_addr(env->img, &(env->bpp), &(env->sizeline), &(env->endian));
	}
}

int mouse_click( int keycode, int x, int y, t_env *env)
{

	(void)x;
	(void)y;
	//ft_putnbr(x);
	ft_putchar('\n');
    //ft_putnbr(y);
    ft_putchar('\n');
    ft_putnbr(keycode);
    ft_putchar('\n');
	if (keycode == 4)
		env->set.coef_zoom += 0.10;
	if (keycode == 5)
		env->set.coef_zoom -=0.10;
	env->set.mse_h_x = (double)x;
	env->set.mse_h_y = (double)y;
    ft_new_img(env);
    mandelbrot(env);
	return(0);
}

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

int my_key_funct(int keycode, t_env *env)
{
	ft_putnbr(keycode);
	ft_putchar('\n');
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	if (keycode == 24)
		env->set.coef_iter += 10;
	if (keycode == 27)
		env->set.coef_iter-= 10;
    if (keycode == 8)
		env->set.coef_zoom -=0.30;
	ft_new_img(env);
	mandelbrot(env);
	return(0);
}

int ft_event(t_env *env)
{
	//mlx_hook(env->win, 6, 0 ,&mouse_pos, env);
	mlx_key_hook(env->win, my_key_funct, env);
	mlx_mouse_hook(env->win, mouse_click, env);
	return(0);
}
