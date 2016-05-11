/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 16:56:53 by yismail           #+#    #+#             */
/*   Updated: 2016/05/11 17:05:28 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void ft_set(t_env *env)
{
	env->set.img_x = 1200;
	env->set.img_y = 1200;
    env->frm.image_x = 1200;
    env->frm.image_y = 1200;
	env->set.coef_iter = 0;
	env->set.coef_zoom = 1;
	env->set.mse_h_x = 0.00;
	env->set.mse_h_y = 0.00;
	env->set.key_zm = 0;
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
	env->oct = (env->bpp / 8);
	mandelbrot(env);
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
