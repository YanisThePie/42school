/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 22:52:32 by yismail           #+#    #+#             */
/*   Updated: 2016/11/19 01:11:59 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_new_img(t_env *env)
{
	if (!env->img)
	{
		env->img = mlx_new_image(env->mlx, env->img_x, env->img_y);
		env->data = mlx_get_data_addr(env->img, &(env->bpp),
		&(env->sizeline), &(env->endian));
	}
	else
		ft_bzero(env->data, 4 * 1200 * 1200);
	return (0);
}

void	set_player(t_env *env)
{
	env->player.posx = 22;
	env->player.posy = 12;
	env->player.dirx = -1;
	env->player.diry = 0;
	env->player.planex = 0;
	env->player.planey = 0.66;
	env->frm.time = 0;
	env->frm.oldtime = 0;
}

void	ft_set_img_win(t_env *env)
{
	env->img_x = 1200;
	env->img_y = 1200;
}

int		ft_window(int argc, char **argv, t_env *env)
{
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
	t_env *env;

	env = NULL;
	ft_window(argc, argv, env);
	free(env);
	return (0);
}
