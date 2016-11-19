/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 01:17:09 by yismail           #+#    #+#             */
/*   Updated: 2016/11/19 04:25:41 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	side_and_step(t_env *env)
{
	while (env->frm.hit == 0)
	{
		if (env->frm.sidedistx < env->frm.sidedisty)
		{
			env->frm.sidedistx += env->frm.deltadistx;
			env->frm.mapx += env->frm.stepx;
			env->frm.side = 0;
			if (env->frm.stepx == 1)
				env->frm.side = 1;
		}
		else
		{
			env->frm.sidedisty += env->frm.deltadisty;
			env->frm.mapy += env->frm.stepy;
			env->frm.side = 2;
			if (env->frm.stepy == 1)
				env->frm.side = 3;
		}
		if (env->worldmap[(int)env->frm.mapx][(int)env->frm.mapy] > 0)
			env->frm.hit = 1;
	}
}

void	wall_detection(t_env *env)
{
	side_and_step(env);
	if (env->frm.side <= 1)
		env->frm.perpwalldist = (env->frm.mapx - env->frm.rayposx +
		(1 - env->frm.stepx) / 2) / env->frm.raydirx;
	else
		env->frm.perpwalldist = (env->frm.mapy - env->frm.rayposy +
		(1 - env->frm.stepy) / 2) / env->frm.raydiry;
}

void	ray_dir(t_env *env)
{
	env->frm.rayposx = env->player.posx;
	env->frm.rayposy = env->player.posy;
	env->frm.raydirx = env->player.dirx +
	(env->player.planex * env->frm.camerax);
	env->frm.raydiry = env->player.diry +
	(env->player.planey * env->frm.camerax);
	env->frm.mapx = (int)env->frm.rayposx;
	env->frm.mapy = (int)env->frm.rayposy;
	env->frm.deltadistx = sqrt((env->frm.raydiry *
	env->frm.raydiry) / (env->frm.raydirx * env->frm.raydirx) + 1);
	env->frm.deltadisty = sqrt((env->frm.raydirx *
	env->frm.raydirx) / (env->frm.raydiry * env->frm.raydiry) + 1);
	env->frm.hit = 0;
	if (env->frm.raydirx < 0 && (env->frm.stepx = -1))
		env->frm.sidedistx = (env->frm.rayposx -
		env->frm.mapx) * env->frm.deltadistx;
	else if ((env->frm.stepx = 1))
		env->frm.sidedistx = (env->frm.mapx -
		env->frm.rayposx + 1) * env->frm.deltadistx;
	if (env->frm.raydiry < 0 && (env->frm.stepy = -1))
		env->frm.sidedisty = (env->frm.rayposy -
		env->frm.mapy) * env->frm.deltadisty;
	else if ((env->frm.stepy = 1))
		env->frm.sidedisty = (env->frm.mapy -
		env->frm.rayposy + 1) * env->frm.deltadisty;
}

int		raycast(t_env *env)
{
	int	x;

	x = 0;
	while (x < env->img_x)
	{
		env->frm.camerax = (double)(2 * x) / (double)env->img_x - 1;
		ray_dir(env);
		wall_detection(env);
		draw_wall(env, x);
		x++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	return (0);
}
