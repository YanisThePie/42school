/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 16:57:16 by yismail           #+#    #+#             */
/*   Updated: 2016/05/11 17:12:03 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void complex_module (t_env *env)
{
	t_color clr;
	int clr_int;

	while (((env->frm.z_r * env->frm.z_r) + (env->frm.z_i * env->frm.z_i)) < 4
	&& env->frm.i < env->frm.iteration_max)
	{
		env->frm.tmp = env->frm.z_r;
		env->frm.z_r = (env->frm.z_r * env->frm.z_r) -
		(env->frm.z_i * env->frm.z_i) + env->frm.c_r;
		env->frm.z_i = 2 * env->frm.z_i * env->frm.tmp + env->frm.c_i;
		env->frm.i += 1;
	}
	if (env->frm.i == env->frm.iteration_max)
		ft_put_pixel_img(env, 0x00000000);
	else
	{
		clr.r = 0;
		clr.g = 0;
		clr.b = (env->frm.i * 255 / env->frm.iteration_max);
		clr_int = color_to_int (clr);
		ft_put_pixel_img(env, clr_int);
	}
}

void nested_loop(t_env *env)
{
	env->frm.x = 0;
	while (env->frm.x < env->frm.image_x)
	{
		env->frm.y = 0;
			while (env->frm.y < env->frm.image_y)
			{
				env->frm.c_r = (env->frm.x / env->frm.zoom_x + env->frm.x1);
				env->frm.c_i = (env->frm.y / env->frm.zoom_y + env->frm.y1);
				env->frm.z_r = 0;
				env->frm.z_i = 0;
				env->frm.i = 0;
				complex_module(env);
				env->frm.y++;
			}
			env->frm.x++;
	}
}

int calcul_center (t_env *env)
{
	double coord_center_x;
	double coord_center_y;

	coord_center_x =  (env->set.mse_h_x / 1200) * (env->frm.x2 - env->frm.x1) + env->frm.x1;
	coord_center_y = (env->set.mse_h_y / 1200) * (env->frm.y2 - env->frm.y1) + env->frm.y1;
	env->frm.x1 = coord_center_x - (0.90) * (env->frm.x2 - env->frm.x1) / 2;
	env->frm.x2 = coord_center_x + (0.90) * (env->frm.x2 - env->frm.x1) / 2;
    env->frm.y1 = coord_center_y - (0.90) * (env->frm.y2 - env->frm.y1) / 2;
    env->frm.y2 = coord_center_y + (0.90) * (env->frm.y2 - env->frm.y1) / 2;
	return(0);
}

int mandelbrot(t_env *env)
{
	 if (env->set.mse_h_x == 0 && env->set.mse_h_y == 0)
	{
		env->frm.x1 = -2.1;
		env->frm.x2 = 0.6;
		env->frm.y1 = -1.2;
		env->frm.y2 = 1.2;
	}
	 else if (env->set.key_zm  == 1)
		 calcul_center(env);
	env->frm.image_x = 1200;
	env->frm.image_y = 1200;
	env->frm.iteration_max = 50 + env->set.coef_iter;
	env->frm.x = 0;
	env->frm.y = 0;
	env->frm.zoom_x = env->set.coef_zoom * env->frm.image_x/(env->frm.x2 - env->frm.x1);
	env->frm.zoom_y = env->set.coef_zoom * env->frm.image_y/(env->frm.y2 - env->frm.y1);
	nested_loop(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	return(0);
}
