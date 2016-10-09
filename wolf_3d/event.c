/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 14:56:29 by yismail           #+#    #+#             */
/*   Updated: 2016/10/09 19:53:51 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*void ft_time(t_env *env)
{
	double frametime;
	
	env->frm.oldTime = env->frm.time;
	env->frm.time = time(NULL);
	printf("time : %f, oldTime : %f\n", env->frm.time , env->frm.oldTime);
	frametime = (env->frm.time - env->frm.oldTime) / 1000;
	//printf("fps : %f", 1.0 / frametime);

	env->player.movespeed = frametime * 5.0;
	env->player.rotspeed = frametime * 3.0;
	}*/

/*
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
*/
/*
int		mouse_pos(int x, int y, t_env *env)
{
	env->set.pos_x = x;
	env->set.pos_y = y;
	env->set.key_zm = 0;
	ft_new_img(env);
	choose_fract(env);
	return (0);
	}*/


int		my_key_funct(int keycode, t_env *env)
{
	if (keycode == 126)
	{
		if (env->worldMap[(int)(env->player.posX + env->player.dirX * 1)][(int)env->player.posY] == 0)
			env->player.posX += env->player.dirX;
		if (env->worldMap[(int)(env->player.posX)][(int)(env->player.posY + env->player.dirY * 1)] == 0)
			env->player.posY += env->player.dirY;
		printf("posX : %f\n dirX: %f\n posY: %f\n dirY: %f\n\n\n", env->player.posX, env->player.dirX, env->player.posY, env->player.dirY); 
	}	
	if (keycode == 125)
	{
		if (env->worldMap[(int)(env->player.posX - env->player.dirX)][(int)env->player.posY] == 0)
			env->player.posX -= env->player.dirX ;
		if (env->worldMap[(int)(env->player.posX)][(int)(env->player.posY - env->player.dirY)] == 0)
			env->player.posY -= env->player.dirY ;
	}
	if (keycode == 124)
	{
		env->player.oldDirX = env->player.dirX;
		env->player.dirX = env->player.dirX * cos(0.09) - env->player.dirY * sin(-0.09);
		env->player.dirY = env->player.oldDirX * sin(-0.09) + env->player.dirY * cos(0.09);
		env->player.oldPlaneX = env->player.planeX;
		env->player.planeX = env->player.planeX * cos(0.09) - env->player.planeY * sin(-0.09);
		env->player.planeY = env->player.oldPlaneX * sin(-0.09) + env->player.planeY * cos(0.09);
		
	}
	if (keycode == 123)
	{
		env->player.oldDirX = env->player.dirX;
		env->player.dirX = env->player.dirX * cos(0.09) - env->player.dirY * sin(0.09);
		env->player.dirY = env->player.oldDirX * sin(0.09) + env->player.dirY * cos(0.09);
		env->player.oldPlaneX = env->player.planeX;
		env->player.planeX = env->player.planeX * cos(0.09) - env->player.planeY * sin(0.09);
		env->player.planeY = env->player.oldPlaneX * sin(0.09) + env->player.planeY * cos(0.09);

	}
	
	ft_new_img(env);
	raycast(env);
	return (0);
}

int		ft_event(t_env *env)
{
	//mlx_hook(env->win, 6, 0, &mouse_pos, env);
	mlx_key_hook(env->win, my_key_funct, env);
	//mlx_mouse_hook(env->win, mouse_click, env);
	return (0);
}
