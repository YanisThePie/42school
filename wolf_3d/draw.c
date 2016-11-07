/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 11:58:48 by yismail           #+#    #+#             */
/*   Updated: 2016/11/07 18:35:41 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		choose_color(t_env *env, int color)
{
	if (env->worldMap[(int)env->frm.mapX][(int)env->frm.mapY] == 1)
		color = 0xFF0000;
	else if (env->worldMap[(int)env->frm.mapX][(int)env->frm.mapY] == 2)
		color = 0x008000;
	else if (env->worldMap[(int)env->frm.mapX][(int)env->frm.mapY] == 3)
		color = 0x0000FF;
	else if (env->worldMap[(int)env->frm.mapX][(int)env->frm.mapY] == 4)
		color = 0xFFFFFF;
	else if (env->worldMap[(int)env->frm.mapX][(int)env->frm.mapY] > 4)
		color = 0xFFFF00;
    
	if (env->frm.side == 1)
		color = color / 2;

	return(color);
}

void	draw_wall(t_env *env, int x)
{
	int y;
	int color;

	color = 0;
	env->draw.lineHeight = abs((int)(env->img_y / env->frm.perpWallDist));
	env->draw.drawStart = -env->draw.lineHeight / 2 + env->img_y / 2;
	if(env->draw.drawStart < 0)
		env->draw.drawStart = 0;
	env->draw.drawEnd = env->draw.lineHeight / 2 + env->img_y / 2;
	if(env->draw.drawEnd >= env->img_y)
		env->draw.drawEnd = env->img_y - 1;
	color = choose_color(env, color);
	y = env->draw.drawStart;
	while (y <= env->draw.drawEnd)
	{
		ft_memcpy(&(env->data[(y * env->sizeline) + (x * env->oct)]), &color, (size_t)(sizeof(int)));
		y++;
	}
}
