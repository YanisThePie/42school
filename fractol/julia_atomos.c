/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_atomos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 12:06:45 by yismail           #+#    #+#             */
/*   Updated: 2016/05/24 12:51:45 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	complex_module_julia_atomos(t_env *env)
{
	while (((env->frm.z_r * env->frm.z_r) + (env->frm.z_i * env->frm.z_i)) < 4
	&& env->frm.i < env->frm.iteration_max)
	{
		env->frm.tmp = env->frm.z_r;
		env->frm.z_r = (env->frm.z_r * env->frm.z_r) -
		(env->frm.z_i * env->frm.z_i) + env->frm.c_r;
		env->frm.z_i = 2 * env->frm.z_i * env->frm.tmp + env->frm.c_i;
		env->frm.i += 1;
	}
	ft_color(env);
}

void	nested_loop_julia_atomos(t_env *env)
{
	env->frm.x = 0;
	while (env->frm.x < env->frm.image_x)
	{
		env->frm.y = 0;
		while (env->frm.y < env->frm.image_y)
		{
			env->frm.c_r = (long double)0.285;
			env->frm.c_i = (long double)0.013;
			env->frm.z_r = env->frm.x / env->frm.zoom_x + env->frm.x1;
			env->frm.z_i = env->frm.y / env->frm.zoom_y + env->frm.y1;
			env->frm.i = 0;
			complex_module_julia_atomos(env);
			env->frm.y++;
		}
		env->frm.x++;
	}
}

int		calcul_center_julia_atomos(t_env *env)
{
	double	coord_center_x;
	double	coord_center_y;

	coord_center_x = (env->set.mse_h_x / 1200) *
	(env->frm.x2 - env->frm.x1) + env->frm.x1;
	coord_center_y = (env->set.mse_h_y / 1200) *
	(env->frm.y2 - env->frm.y1) + env->frm.y1;
	env->frm.x1 = coord_center_x - (0.90) * (env->frm.x2 - env->frm.x1) / 2;
	env->frm.x2 = coord_center_x + (0.90) * (env->frm.x2 - env->frm.x1) / 2;
	env->frm.y1 = coord_center_y - (0.90) * (env->frm.y2 - env->frm.y1) / 2;
	env->frm.y2 = coord_center_y + (0.90) * (env->frm.y2 - env->frm.y1) / 2;
	return (0);
}

int		julia_atomos(t_env *env)
{
	if (env->set.mse_h_x == 0 && env->set.mse_h_y == 0)
	{
		env->frm.x1 = -1;
		env->frm.x2 = 1;
		env->frm.y1 = -1.2;
		env->frm.y2 = 1.2;
	}
	else if (env->set.key_zm == 1)
		calcul_center_julia_atomos(env);
	env->frm.image_x = 1200;
	env->frm.image_y = 1200;
	env->frm.iteration_max = 100 + env->set.coef_iter;
	env->frm.x = 0;
	env->frm.y = 0;
	env->frm.zoom_x = env->set.coef_zoom *
	env->frm.image_x / (env->frm.x2 - env->frm.x1);
	env->frm.zoom_y = env->set.coef_zoom *
	env->frm.image_y / (env->frm.y2 - env->frm.y1);
	nested_loop_julia_atomos(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	return (0);
}
