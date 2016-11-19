/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 11:58:48 by yismail           #+#    #+#             */
/*   Updated: 2016/11/19 03:44:49 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		choose_color(t_env *env)
{
	if (env->worldmap[(int)env->frm.mapx][(int)env->frm.mapy] == 4)
		return (0xFF0000);
	if (env->frm.side == 1)
		return (0xBCA9F5);
	if (env->frm.side == 2)
		return (0xA9F5A9);
	if (env->frm.side == 3)
		return (0x81DAF5);
	return (0xF2F5A9);
}

void	draw_wall(t_env *env, int x)
{
	int y;
	int color;

	color = 0;
	env->draw.lineheight = abs((int)(env->img_y / env->frm.perpwalldist));
	env->draw.drawstart = -env->draw.lineheight / 2 + env->img_y / 2;
	if (env->draw.drawstart < 0)
		env->draw.drawstart = 0;
	env->draw.drawend = env->draw.lineheight / 2 + env->img_y / 2;
	if (env->draw.drawend >= env->img_y)
		env->draw.drawend = env->img_y - 1;
	color = choose_color(env);
	y = env->draw.drawstart;
	while (y <= env->draw.drawend)
	{
		ft_memcpy(&(env->data[(y * env->sizeline)
		+ (x * env->oct)]), &color, (size_t)(sizeof(int)));
		y++;
	}
}
