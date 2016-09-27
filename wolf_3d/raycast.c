/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 01:17:09 by yismail           #+#    #+#             */
/*   Updated: 2016/09/27 19:39:42 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"


void set_player(t_env *env)
{
	env->player.posX = 22.f;
	env->player.posY = 12.f;
	env->player.dirX = -1.f;
	env->player.dirY = 0.f;
	env->player.planeX = 0.f;
	env->player.planeY = 0.66;
	env->frm.time = 0.f;
	env->frm.oldTime = 0.f;
}

void draw_wall(t_env *env, int x)
{
	int color;
// creuser ici!
	env->draw.lineHeight = ((int)env->img_y / env->frm.perpWallDist);
	printf("perpwalldist1 : %f  img_y %d \n", env->frm.perpWallDist, (int)env->img_y);
	printf("lineheight1 : %f \n", env->draw.lineHeight);
	env->draw.drawStart = -env->draw.lineHeight / 2.f + env->img_y / 2.f;
	if(env->draw.drawStart < 0)
		env->draw.drawStart = 0;
	env->draw.drawEnd = env->draw.lineHeight / 2.f + env->img_y / 2.f;
    if(env->draw.drawEnd >= env->img_y)
		env->draw.drawEnd = env->img_y - 1.f;
	/*env->worldMap[(int)env->frm.mapX][(int)env->frm.mapY] == 1.f ? color = 0xFF0000 : (env->worldMap[(int)env->frm.mapX][(int)env->frm.mapY] == 2.f) ? 0x008000 : (env->worldMap[(int)env->frm.mapX][(int)env->frm.mapY] == 3.f) ? 0x0000FF : (env->worldMap[(int)env->frm.mapX][(int)env->frm.mapY] == 4.f) ? 0xFFFFFF : (env->worldMap[(int)env->frm.mapX][(int)env->frm.mapY] > 4.f) ? 0xFFFF00 : ft_putstr("problem");*/
	color = 0xFFFFFF;
	if (env->frm.side == 1.f)
		color = color / 2.f;
	
	printf("D : drawstart : %f/ drawend : %f/ x : %f\n\n",env->draw.drawStart, env->draw.drawEnd, (double)x); 
	while (x <= env->draw.drawEnd)
		{
			if (x >= env->draw.drawStart)
			{
				ft_memcpy(&(env->data[((int)env->draw.lineHeight * (int)env->sizeline) + ((int)x * (int)env->oct)]), &color, (size_t)(sizeof(int)));
				printf("Did on px: %d with color : %d\n", x, color);
			}
			x++;
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
			env->frm.side = 1.f;
		}
		if (env->worldMap[(int)env->frm.mapX][(int)env->frm.mapY] > 0)
			env->frm.hit = 1.f;
	}
	if (env->frm.side == 0)
		env->frm.perpWallDist = ((double)env->frm.mapX - env->frm.rayPosX + (1.f - env->frm.stepX) / 2.f) / env->frm.rayDirX;// probleme ici!!
	else
		ft_putnbr(9);
		env->frm.perpWallDist = (env->frm.mapY - env->frm.rayPosY + (1.f - env->frm.stepY) / 2.f) /env->frm.rayDirY;
}

void ray_dir(t_env *env, double x)
{
	env->frm.cameraX = 2 * x / (env->img_x - 1);
	env->frm.rayPosX = env->player.posX;
	env->frm.rayPosY = env->player.posY;
	env->frm.rayDirX = env->player.dirX + env->player.planeX * env->frm.cameraX;
	env->frm.rayDirY = env->player.dirY + env->player.planeY * env->frm.cameraX;
	env->frm.mapX = env->frm.rayPosX;
	env->frm.mapY = env->frm.rayPosY;
	env->frm.deltaDistX = sqrt(1.f + (env->frm.rayDirY * env->frm.rayDirY) / (env->frm.rayDirX * env->frm.rayDirX));
	env->frm.deltaDistY = sqrt(1.f + (env->frm.rayDirX * env->frm.rayDirX) / (env->frm.rayDirY * env->frm.rayDirY));
	env->frm.hit = 0;
	env->frm.rayDirX < 0 ? ((env->frm.stepX = -1.f) && (env->frm.sideDistX = env->frm.rayPosX - env->frm.mapX * env->frm.deltaDistX)) : ((env->frm.stepX = 1.f) && (env->frm.sideDistX = (env->frm.mapX + 1.f - env->frm.rayPosX) * env->frm.deltaDistX));
	env->frm.rayDirY < 0 ? ((env->frm.stepY = -1.f) && (env->frm.sideDistY = env->frm.rayPosY - env->frm.mapY * env->frm.deltaDistY)) : ((env->frm.stepY = 1.f) && (env->frm.sideDistY = (env->frm.mapY + 1.f - env->frm.rayPosY) * env->frm.deltaDistY));
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
