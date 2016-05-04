#include "fractol.h"

void ft_put_pixel_img(t_env *env, t_form *form, int clr_int)
{
	//env = env;
	if ((form->x >= 0 && form->x <= 1200)
		&& (form->y >= 0 && form->y <= 1200))
	{
		if (env->data == NULL)
			ft_putnbr((int)env->data);
		else
		{
			//ft_putstr("thisis");
			ft_putnbr((int)env->data);
			//ft_putnbr((form->y * env->sizeline) + (form->x * 4));
			ft_putchar('\n');
			//ft_putchar('\n');
			ft_memcpy(&(env->data[(form->y * env->sizeline) + (form->x * 4)]),
					  &clr_int, (size_t)(sizeof(int)));
		}
	}
	else
		ft_putstr("oh no");
}

void ft_set(t_env *env)
{
	env->setup.img_x = 1200;
	env->setup.img_y = 1200;
}

int ft_window()
{
	t_env env;

	env.mlx = mlx_init();
	env.img = NULL;
	env.data = NULL;
	env.win = mlx_new_window(env.mlx, 1200, 1200, "fractol");
	ft_set(&env);
	ft_new_img(&env);
	ft_putnbr((int) env.img);
	//env.oct = (env.bpp / 8);
	mandelbrot(&env);
	mlx_put_image_to_window(env.mlx, env.win, env.img, 0, 0);
	ft_event(&env);
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
