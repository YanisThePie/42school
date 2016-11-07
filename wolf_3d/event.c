/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 14:56:29 by yismail           #+#    #+#             */
/*   Updated: 2016/11/07 11:58:09 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

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

int     loop_hook(t_env *env)
{
		int mmx;
		int mmy;

		mmx = env->img_x - env->frm.mapX * 4;
		mmy = env->img_y -  env->frm.mapY * 4;
		if (!env->img)
		{
			env->img = mlx_new_image(env->mlx, env->img_x, env->img_y);
			env->data = mlx_get_data_addr(env->img, &(env->bpp), &(env->sizeline), &(env->endian));
		}
		else
		{
			mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
			mlx_do_sync(env->mlx);
		}
		return (1);
}

int		ft_event(t_env *env)
{
	mlx_hook(env->win, 2, (1L << 0), my_key_funct, env);
	mlx_loop_hook(env->mlx, loop_hook, env);
	mlx_loop(env->mlx);
	return (0);
}
