#include "fractol.h"

void ft_new_img(t_env *env)
{
	if (!env->img)
	{
		//ft_putnbr(1);
		env->img = mlx_new_image(env->mlx, env->setup.img_x, env->setup.img_y);
		env->data = mlx_get_data_addr(env->img, &(env->bpp), &(env->sizeline), &(env->endian));
		env->setup.keep_ad = (env->data);
	}
	else
	{
		ft_putnbr(2);
		ft_putnbr((int)env->setup.keep_ad);
		env->data = env->setup.keep_ad;
		//mlx_destroy_image(env->mlx, env->img);
		//ft_bzero(env->data, 4 * 1200 * 1200);
		//env->img = mlx_new_image(env->mlx, env->setup.img_x, env->setup.img_y);
		//env->data = mlx_get_data_addr(env->img, &(env->bpp), &(env->sizeline), &(env->endian));
	}
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
	//ft_putnbr(keycode);
	ft_putchar('\n');
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	//if (keycode == 24)
	//env->coef_iter += 50;
	ft_new_img(env);
	mandelbrot(env);
	return(0);
}

int ft_event(t_env *env)
{
	//mlx_hook(env->win, 6, 0 ,&mouse_pos, &env);
	mlx_key_hook(env->win, my_key_funct, &env);
	//mlx_mouse_hook(env->win, mouse_click, &env);
	return(0);
}
