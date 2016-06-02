/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 14:56:29 by yismail           #+#    #+#             */
/*   Updated: 2016/05/24 15:00:17 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_new_img(t_env *env)
{
	if (!env->img)
	{
		env->img = mlx_new_image(env->mlx, env->set.img_x, env->set.img_y);
		env->data = mlx_get_data_addr(env->img,
		&(env->bpp), &(env->sizeline), &(env->endian));
	}
	else
		ft_bzero(env->data, 4 * 1200 * 1200);
}

int		mouse_click(int keycode, int x, int y, t_env *env)
{
	env->set.key_zm = 0;
	if (keycode == 1)
	{
		env->set.key_zm = 1;
		env->set.coef_zoom = 1.10;
		env->set.coef_iter += 2;
	}
	env->set.mse_h_x = (double)x;
	env->set.mse_h_y = (double)y;
	ft_new_img(env);
	choose_fract(env);
	return (0);
}

int		mouse_pos(int x, int y, t_env *env)
{
	env->set.pos_x = x;
	env->set.pos_y = y;
	env->set.key_zm = 0;
	ft_new_img(env);
	choose_fract(env);
	return (0);
}

int		my_key_funct(int keycode, t_env *env)
{
	env->set.key_zm = 0;
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	if (keycode == 24)
		env->set.coef_iter += 10;
	if (keycode == 27)
		env->set.coef_iter -= 10;
	if (keycode == 15)
		ft_set(env);
	if (keycode == 8)
	{
		if (env->set.key_c < 3)
			env->set.key_c += 1;
		else
			env->set.key_c = 1;
	}
	ft_new_img(env);
	choose_fract(env);
	return (0);
}

int		ft_event(t_env *env)
{
	mlx_hook(env->win, 6, 0, &mouse_pos, env);
	mlx_key_hook(env->win, my_key_funct, env);
	mlx_mouse_hook(env->win, mouse_click, env);
	return (0);
}
