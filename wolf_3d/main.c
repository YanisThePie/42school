/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 22:52:32 by yismail           #+#    #+#             */
/*   Updated: 2016/11/11 15:07:49 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_new_img(t_env *env)
{
	if (!env->img)
	{
		env->img = mlx_new_image(env->mlx, env->img_x, env->img_y);
		env->data = mlx_get_data_addr(env->img, &(env->bpp),
		&(env->sizeline), &(env->endian));
	}
	else
		ft_bzero(env->data, 4 * 1200 * 1200);
}

void	set_player(t_env *env)
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

void	ft_set_img_win(t_env *env)
{
	env->img_x = 1200;
	env->img_y = 1200;
}

int		ft_window(int argc, char **argv)
{
	t_env *env;

	env = (t_env*)malloc(sizeof(t_env));
	env->mlx = mlx_init();
	env->img = NULL;
	env->data = NULL;
	ft_set_img_win(env);
	env->win = mlx_new_window(env->mlx, env->img_x, env->img_y, "Wolf3d");
	ft_new_img(env);
	env->oct = (env->bpp / 8);
	ft_parsing(argc, argv, env);
	set_player(env);
	raycast(env);
	ft_event(env);
	mlx_loop(env->mlx);
	return (0);
}

int		main(int argc, char **argv)
{
	ft_window(argc, argv);
	return (0);
}
