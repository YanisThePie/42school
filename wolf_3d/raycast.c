/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 01:17:09 by yismail           #+#    #+#             */
/*   Updated: 2016/07/26 11:23:36 by yismail          ###   ########.fr       */
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

void draw_wall(t_env *env, int x)
{
	int color;

	env->draw.lineHeight = (int)(env->img_x / env->frm.perpWallDist);
	env->draw.drawStart = -env->draw.lineHeight / 2 + env->img_x / 2;
	if(env->draw.drawStart < 0)
		env->draw.drawStart = 0;
	env->draw.drawEnd = env->draw.lineHeight / 2 + env->img_x / 2;
    if(env->draw.drawEnd >= env->img_x)
		env->draw.drawEnd = env->img_x - 1;

	env->worldMap[env->frm.mapX][env->frm.mapY] == 1 ? color = 0xFF0000 : (env->worldMap[env->frm.mapX][env->frm.mapY] == 2) ? 0x008000 : (env->worldMap[env->frm.mapX][env->frm.mapY] == 3) ? 0x0000FF : (env->worldMap[env->frm.mapX][env->frm.mapY] == 4) ? 0xFFFFFF : (env->worldMap[env->frm.mapX][env->frm.mapY] > 4) ? 0xFFFF00 : ft_putstr("problem");

	if (env->frm.side == 1)
		color = color / 2;
	ft_putstr("X :");
	ft_putnbr(x);
	ft_putchar('\n');
    ft_putstr("drawStart");
    ft_putnbr(env->draw.drawStart);
    ft_putchar('\n');
    ft_putstr("drawend");
    ft_putnbr(env->draw.drawEnd);
    ft_putchar('\n');
	if (x <= env->draw.drawStart && x >= env->draw.drawEnd)
		{
			ft_putchar('c');
        ft_memcpy(&(env->data[(env->frm.y * env->sizeline) + (env->frm.x * env->oct)]), &color, (size_t)(sizeof(int)));
		}
}

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
		if (env->worldMap[env->frm.mapX][env->frm.mapY] > 0)
			env->frm.hit = 1;
	}
	if (env->frm.side == 0)
		env->frm.perpWallDist = (env->frm.mapX - env->frm.rayPosX + (1 - env->frm.stepX) / 2) / env->frm.rayDirX;
	else
		env->frm.perpWallDist = (env->frm.mapY - env->frm.rayPosY + (1 - env->frm.stepY) / 2) /env->frm.rayDirY;
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
		wall_detection(env);
		draw_wall(env, x);
		x++;
	} 
}

int raycast (t_env *env)
{
	set_player(env);
	vector_calc(env);
    mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	return(0);
}
