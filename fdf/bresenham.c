/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 12:33:16 by yismail           #+#    #+#             */
/*   Updated: 2016/04/12 12:33:19 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		color_to_int(t_color c)
{
	return ((c.r & 0xff) << 16) | ((c.g & 0xff) << 8) | (c.b & 0xff);
}

t_color	calcul_delta(int t_color_act, int t_color_next, int n)
{
	t_color delta;

	delta.r = ((t_color_next >> 16 & 0xff) - (t_color_act >> 16 & 0xff)) / n;
	delta.g = ((t_color_next >> 8 & 0xff) - (t_color_act >> 8 & 0xff)) / n;
	delta.b = ((t_color_next & 0xff) - (t_color_act & 0xff)) / n;
	return (delta);
}

void	ligne_n1(t_bresen br, void *mlx, void *win, t_projdots spc)
{
	t_color n1;
	t_color d;

	d.r = (spc.t_color_act >> 16) & 0xff;
	d.g = (spc.t_color_act >> 8) & 0xff;
	d.b = spc.t_color_act & 0xff;
	br.cumul = br.dx / 2;
	br.i = 1;
	n1 = calcul_delta(spc.t_color_act, spc.t_color_next, br.dx - br.i);
	while (br.i <= br.dx)
	{
		br.x += br.xinc;
		br.cumul += br.dy;
		if (br.cumul >= br.dx)
		{
			br.cumul -= br.dx;
			br.y += br.yinc;
		}
		d.r += n1.r;
		d.g += n1.g;
		d.b += n1.b;
		mlx_pixel_put(mlx, win, br.x, br.y, color_to_int(d));
		br.i++;
	}
}

void	ligne_n2(t_bresen br, void *mlx, void *win, t_projdots spc)
{
	t_color n2;
	t_color d;

	d.r = (spc.t_color_act >> 16) & 0xff;
	d.g = (spc.t_color_act >> 8) & 0xff;
	d.b = spc.t_color_act & 0xff;
	br.cumul = br.dy / 2;
	br.i = 1;
	n2 = calcul_delta(spc.t_color_act, spc.t_color_next, br.dy - br.i);
	while (br.i <= br.dy)
	{
		br.y += br.yinc;
		br.cumul += br.dx;
		if (br.cumul >= br.dy)
		{
			br.cumul -= br.dy;
			br.x += br.xinc;
		}
		d.r += n2.r;
		d.g += n2.g;
		d.b += n2.b;
		mlx_pixel_put(mlx, win, br.x, br.y, color_to_int(d));
		br.i++;
	}
}

void	ligne(t_projdots spc, void *mlx, void *win)
{
	t_bresen br;

	br.x = spc.x0;
	br.y = spc.y0;
	br.dx = spc.x1 - spc.x0;
	br.dy = spc.y1 - spc.y0;
	br.xinc = (br.dx > 0) ? 1 : -1;
	br.yinc = (br.dy > 0) ? 1 : -1;
	br.dx = abs(br.dx);
	br.dy = abs(br.dy);
	mlx_pixel_put(mlx, win, br.x, br.y, spc.t_color_act);
	if (br.dx > br.dy)
		ligne_n1(br, mlx, win, spc);
	else
		ligne_n2(br, mlx, win, spc);
}
