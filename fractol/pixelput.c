#include "fractol.h"

void ft_put_pixel_img(t_env *env, int clr_int)
{
	if ((env->frm.x >= 0 && env->frm.x <= 1200)
		&& (env->frm.y >= 0 && env->frm.y <= 1200))
	{
		ft_memcpy(&(env->data[(env->frm.y * env->sizeline) +
							  (env->frm.x * env->oct)]), &clr_int, (size_t)(sizeof(int)));
	}
}

void ft_color(t_env *env)
{
	t_color clr;
	int		clr_int;

	if (env->frm.i == env->frm.iteration_max)
		ft_put_pixel_img(env, 0xffffff);
	
	if (env->frm.i <= env->frm.iteration_max / 4 && env->frm.i >= env->frm.iteration_max /5)
	{
		clr.r = (env->frm.i * 255 / env->frm.iteration_max);
		clr.g = (env->frm.i * 255 / env->frm.iteration_max);
		clr.b = 0;
		clr_int = color_to_int (clr);
		ft_put_pixel_img(env, clr_int);
	}

	if (env->frm.i < env->frm.iteration_max / 5 && env->frm.i >= env->frm.iteration_max /6)
	{
		clr.r = (env->frm.i * 255 / env->frm.iteration_max);
		clr.g = 0;
		clr.b = (env->frm.i * 255 / env->frm.iteration_max);
		clr_int = color_to_int (clr);
		ft_put_pixel_img(env, clr_int);
	}
	
/*	else
	{
		clr.r = (env->frm.i * 255 / env->frm.iteration_max);
		clr.g = (env->frm.i * 255 / env->frm.iteration_max);
		clr.b = (env->frm.i * 255 / env->frm.iteration_max);
		clr_int = color_to_int (clr);
		ft_put_pixel_img(env, clr_int);
	}
*/
}

