/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixelput.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 15:28:00 by yismail           #+#    #+#             */
/*   Updated: 2016/05/18 18:59:12 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

void ft_put_pixel_img(t_env *env, int clr_int)
{
	if ((env->frm.x >= 0 && env->frm.x <= 1200)
		&& (env->frm.y >= 0 && env->frm.y <= 1200))
	{
		ft_memcpy(&(env->data[(env->frm.y * env->sizeline) +
							  (env->frm.x * env->oct)]), &clr_int, (size_t)(sizeof(int)));
	}
}

int ft_color(t_env *env)
{
	if (env->frm.i == env->frm.iteration_max)
	{
		ft_put_pixel_img(env, 0x0000ff);
		return(0);
	}
	if (env->frm.i <= env->frm.iteration_max / 4 && env->frm.i >= env->frm.iteration_max /5)
	{
		ft_put_pixel_img(env, 0xFE0EEB);
		return(0);
	}

	if (env->frm.i < env->frm.iteration_max / 5 && env->frm.i >= env->frm.iteration_max /6)
	{
		ft_put_pixel_img(env, 0x610061);
		return(0);
		}

	if (env->frm.i <= 3)
	{
		ft_put_pixel_img(env, 0x00fff9);
		return(0);
	}
	
	else
		ft_put_pixel_img(env, 0x00CD00);
	return (0);
}

