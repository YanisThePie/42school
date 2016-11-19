/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 14:56:29 by yismail           #+#    #+#             */
/*   Updated: 2016/11/19 03:41:00 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	my_key_funct2(int keycode, t_env *env)
{
	if (keycode == 123)
	{
		env->player.olddirx = env->player.dirx;
		env->player.dirx = env->player.dirx * cos(0.04)
		- env->player.diry * sin(0.04);
		env->player.diry = env->player.olddirx * sin(0.04)
		+ env->player.diry * cos(0.04);
		env->player.oldplanex = env->player.planex;
		env->player.planex = env->player.planex * cos(0.04)
		- env->player.planey * sin(0.04);
		env->player.planey = env->player.oldplanex * sin(0.04) \
		+ env->player.planey * cos(0.04);
	}
	if (keycode == 126)
	{
		if (env->worldmap[(int)(env->player.posx +
		env->player.dirx * 0.06)][(int)env->player.posy] == 0)
			env->player.posx += env->player.dirx * 0.06;
		if (env->worldmap[(int)(env->player.posx)]
		[(int)(env->player.posy + env->player.diry * 0.06)] == 0)
			env->player.posy += env->player.diry * 0.06;
	}
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	ft_new_img(env);
}

int		my_key_funct(int keycode, t_env *env)
{
	if (keycode == 125)
	{
		if (env->worldmap[(int)(env->player.posx - env->player.dirx
		* 0.06)][(int)env->player.posy] == 0)
			env->player.posx -= env->player.dirx * 0.06;
		if (env->worldmap[(int)(env->player.posx)][(int)(env->player.posy
		- env->player.diry * 0.06)] == 0)
			env->player.posy -= env->player.diry * 0.06;
	}
	if (keycode == 124)
	{
		env->player.olddirx = env->player.dirx;
		env->player.dirx = env->player.dirx * cos(0.04)
		- env->player.diry * sin(-0.04);
		env->player.diry = env->player.olddirx * sin(-0.04)
		+ env->player.diry * cos(0.04);
		env->player.oldplanex = env->player.planex;
		env->player.planex = env->player.planex * cos(0.04)
		- env->player.planey * sin(-0.04);
		env->player.planey = env->player.oldplanex *
		sin(-0.04) + env->player.planey * cos(0.04);
	}
	my_key_funct2(keycode, env);
	raycast(env);
	return (0);
}

int		loop_hook(t_env *env)
{
	int		mmx;
	int		mmy;

	mmx = env->img_x - env->frm.mapx * 4;
	mmy = env->img_y - env->frm.mapy * 4;
	if (!env->img)
	{
		env->img = mlx_new_image(env->mlx, env->img_x, env->img_y);
		env->data = mlx_get_data_addr(env->img,
		&(env->bpp), &(env->sizeline), &(env->endian));
	}
	else
	{
		mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
		mlx_do_sync(env->mlx);
	}
	return (1);
}

int		red_cross(int key, t_data *d)
{
	(void)key;
	(void)d;
	exit(0);
	return (0);
}

int		ft_event(t_env *env)
{
	mlx_hook(env->win, 2, (1L << 0), my_key_funct, env);
	mlx_hook(env->win, 17, (1L << 17), &red_cross, env);
	mlx_loop_hook(env->mlx, loop_hook, env);
	mlx_loop(env->mlx);
	return (0);
}
