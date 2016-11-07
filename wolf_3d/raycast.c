/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 01:17:09 by yismail           #+#    #+#             */
/*   Updated: 2016/11/07 12:27:19 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "wolf3d.h"
#include <stdlib.h>


void wall_detection(t_env *env)
{
	while (env->frm.hit == 0)
	{
		if (env->frm.sideDistX < env->frm.sideDistY)
		{
			env->frm.sideDistX += env->frm.deltaDistX;
			env->frm.mapX += env->frm.stepX;
			env->frm.side = 0;
		}
		else
		{
			env->frm.sideDistY += env->frm.deltaDistY;
			env->frm.mapY += env->frm.stepY;
			env->frm.side = 1;
		}
		if (env->worldMap[(int)env->frm.mapX][(int)env->frm.mapY] > 0)
			env->frm.hit = 1;
	}
	if (env->frm.side == 0)
		env->frm.perpWallDist = fabs((env->frm.mapX - env->frm.rayPosX + (1 - env->frm.stepX) / 2) / env->frm.rayDirX);// probleme ici!!
	else
		env->frm.perpWallDist = fabs((env->frm.mapY - env->frm.rayPosY + (1 - env->frm.stepY) / 2) /env->frm.rayDirY);
}

void ray_dir(t_env *env, double x)
{
	env->frm.cameraX = 2 * x / (double)(env->img_x) - 1;
	env->frm.rayPosX = env->player.posX;
	env->frm.rayPosY = env->player.posY;
	env->frm.rayDirX = env->player.dirX + env->player.planeX * env->frm.cameraX;
	env->frm.rayDirY = env->player.dirY + env->player.planeY * env->frm.cameraX;
	env->frm.mapX = env->frm.rayPosX;
	env->frm.mapY = env->frm.rayPosY;
	env->frm.deltaDistX = sqrt(1 + (env->frm.rayDirY * env->frm.rayDirY) / (env->frm.rayDirX * env->frm.rayDirX));
	env->frm.deltaDistY = sqrt(1 + (env->frm.rayDirX * env->frm.rayDirX) / (env->frm.rayDirY * env->frm.rayDirY));
	env->frm.hit = 0;
	if (env->frm.rayDirX < 0) 
		((env->frm.stepX = -1) && (env->frm.sideDistX = (env->frm.rayPosX - env->frm.mapX) * env->frm.deltaDistX)); 
	else
		((env->frm.stepX = 1) && (env->frm.sideDistX = (env->frm.mapX + 1.0 - env->frm.rayPosX) * env->frm.deltaDistX));
	if(env->frm.rayDirY < 0)
		((env->frm.stepY = -1) && (env->frm.sideDistY = (env->frm.rayPosY - env->frm.mapY) * env->frm.deltaDistY));
	else
		((env->frm.stepY = 1) && (env->frm.sideDistY = (env->frm.mapY + 1.0 - env->frm.rayPosY) * env->frm.deltaDistY));
}

int raycast (t_env *env)
{
    int x;

    x = 0;
    while(x < env->img_x)
    {
        ray_dir(env, x);
        wall_detection(env);
        draw_wall(env, x);
        x++;
    }
    mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	return(0);
}
