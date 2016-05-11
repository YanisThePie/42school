#include "fractol.h"

void ft_put_pixel_img(t_env *env, t_form *form, int clr_int)
{
	//env = env;
	if ((form->x >= 0 && form->x <= 1200)
		&& (form->y >= 0 && form->y <= 1200))
	{
		ft_memcpy(&(env->data[(form->y * env->sizeline) + (form->x * 4)]),
		&clr_int, (size_t)(sizeof(int)));
	}
}

void ft_set(t_env *env)
{
	env->set.img_x = 1200;
	env->set.img_y = 1200;
	env->set.coef_iter = 0;
	env->set.coef_zoom = 1;
	env->set.mse_h_x = 0.00;
	env->set.mse_h_x = 0.00;
}

int ft_window()
{
	t_env *env;

	env = (t_env*)malloc(sizeof(t_env));
	env->mlx = mlx_init();
	env->img = NULL;
	env->data = NULL;
	env->win = mlx_new_window(env->mlx, 1200, 1200, "fractol");
	ft_set(env);
	ft_new_img(env);
	//env.oct = (env.bpp / 8);
	mandelbrot(env);
	//mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	ft_event(env);
	mlx_loop(env->mlx);
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
