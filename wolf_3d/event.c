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


void CalculateFrameRate(t_env *env)
{
	static float framesPerSecond    = 0.0f;       // This will store our fps
	static float lastTime   = 0.0f;       // This will hold the time from the last frame
	float currentTime = time(NULL) * 0.001f;
	++framesPerSecond;
	if( currentTime - lastTime > 1.0f )
	{
		lastTime = currentTime;
		fprintf(stderr, "\nCurrent Frames Per Second: %d\n\n", (int)framesPerSecond);
		framesPerSecond = 0;
	}
	//env->player.movespeed = framesPerSecond * 5.0;
	//env->player.rotspeed = framesPerSecond * 3.0;
	
	env->player.movespeed = 1 * 5;
	env->player.rotspeed = 1 * 3;
}

int		my_key_funct(int keycode, t_env *env)
{
	ft_putnbr(keycode);
	CalculateFrameRate(env);
	if (keycode == 126)
	{
		if (env->worldMap[(int)(env->player.posX + env->player.dirX * env->player.movespeed)][(int)env->player.posY] == 0)
			env->player.posX += env->player.dirX * env->player.movespeed;
		if (env->worldMap[(int)(env->player.posX)][(int)(env->player.posY + env->player.dirY * env->player.movespeed)] == 0)
			env->player.posY += env->player.dirY * env->player.movespeed;
	}	
	if (keycode == 125)
	{
		if (env->worldMap[(int)(env->player.posX - env->player.dirX * env->player.movespeed)][(int)env->player.posY] == 0)
			env->player.posX -= env->player.dirX * env->player.movespeed;
		if (env->worldMap[(int)(env->player.posX)][(int)(env->player.posY - env->player.dirY * env->player.movespeed)] == 0)
			env->player.posY -= env->player.dirY * env->player.movespeed;
	}
	if (keycode == 124)
	{
		env->player.oldDirX = env->player.dirX;
		env->player.dirX = env->player.dirX * cos(-env->player.rotspeed) - env->player.dirY * sin(-env->player.rotspeed);
		env->player.dirY = env->player.oldDirX * sin(-env->player.rotspeed) + env->player.dirY * cos(-env->player.rotspeed);
		env->player.oldPlaneX = env->player.planeX;
		env->player.planeX = env->player.planeX * cos(-env->player.rotspeed) - env->player.planeY * sin(-env->player.rotspeed);
		env->player.planeY = env->player.oldPlaneX * sin(-env->player.rotspeed) + env->player.planeY * cos(-env->player.rotspeed);
		
	}
	if (keycode == 123)
	{
		env->player.oldDirX = env->player.dirX;
		env->player.dirX = env->player.dirX * cos(-env->player.rotspeed) - env->player.dirY * sin(env->player.rotspeed);
		env->player.dirY = env->player.oldDirX * sin(env->player.rotspeed) + env->player.dirY * cos(env->player.rotspeed);
		env->player.oldPlaneX = env->player.planeX;
		env->player.planeX = env->player.planeX * cos(env->player.rotspeed) - env->player.planeY * sin(-env->player.rotspeed);
		env->player.planeY = env->player.oldPlaneX * sin(env->player.rotspeed) + env->player.planeY * cos(env->player.rotspeed);

	}
	
	ft_new_img(env);
	raycast(env);
	return (0);
}

int		ft_event(t_env *env)
{
	env->frm.time = 0;
	env->frm.oldTime = 0;
	//mlx_hook(env->win, 6, 0, &mouse_pos, env);
	mlx_key_hook(env->win, my_key_funct, env);
	//mlx_mouse_hook(env->win, mouse_click, env);
	return (0);
}
