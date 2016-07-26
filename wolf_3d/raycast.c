/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 01:17:09 by yismail           #+#    #+#             */
/*   Updated: 2016/07/26 03:49:30 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"


void set_player(t_env *env)
{
	env->player.posX = 22;
	env->player.posY = 12;
	env->player.dirX = -1;
	env->player.dirY = 0;
	env->player.planeX = 0;
	env->player.planeY = 0.66;
	env->frm.time = 0;
	env->frm.oldTime = 0;
}

void ray_dir(t_env *env, int x)
{
	env->frm.cameraX = 2 * x / (env->img_x - 1);
	env->frm.rayPosX = env->player.posX;
	env->frm.rayPosY = env->player.posY;
	env->frm.rayDirX = env->player.dirX + env->player.planeX * env->frm.cameraX;
	env->frm.rayDirY = env->player.dirY + env->player.planeY * env->frm.cameraX;
	env->frm.mapX = (int)env->frm.rayPosX;
	env->frm.mapX = (int)env->frm.rayPosX;
	env->frm.deltaDistX = sqrt(1 + (env->frm.rayDirY * env->frm.rayDirY) / (env->frm.rayDirX * env->frm.rayDirX));
	env->frm.deltaDistY = sqrt(1 + (env->frm.rayDirX * env->frm.rayDirX) / (env->frm.rayDirY * env->frm.rayDirY));
	env->frm.hit = 0;
	env->frm.rayDirX < 0 ? ((env->frm.stepX = -1) && (env->frm.sideDistX = env->frm.rayPosX - env->frm.mapX * env->frm.deltaDistX)) : ((env->frm.stepX = 1) && (env->frm.sideDistX = (env->frm.mapX + 1.0 - env->frm.rayPosX) * env->frm.deltaDistX));
	env->frm.rayDirY < 0 ? ((env->frm.stepY = -1) && (env->frm.sideDistY = env->frm.rayPosY - env->frm.mapY * env->frm.deltaDistY)) : ((env->frm.stepY = 1) && (env->frm.sideDistY = (env->frm.mapY + 1.0 - env->frm.rayPosY) * env->frm.deltaDistY));
}

void vector_calc(t_env *env)
{
	int x;

	x = 0;
	while(x < env->img_x)
	{
		ray_dir(env, x);
		
		x++;
	} 
}

int raycast (t_env *env)
{
	set_player(env);
	vector_calc(env);
    ft_putnbr(env->frm.sizemap_x);
    ft_putnbr(env->frm.sizemap_y);
    mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	return(0);
}
