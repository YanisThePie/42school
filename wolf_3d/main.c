/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 22:52:32 by yismail           #+#    #+#             */
/*   Updated: 2016/09/27 18:35:42 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void    ft_put_pixel_img(t_env *env, int clr_int)
{
    if ((env->frm.x >= 0 && env->frm.x <= 1200)
        && (env->frm.y >= 0 && env->frm.y <= 1200))
    {
        ft_memcpy(&(env->data[((int)env->frm.y * env->sizeline) + ((int)env->frm.x * env->oct)]), &clr_int, (size_t)(sizeof(int)));
    }
}

void    ft_new_img(t_env *env)
{
    if (!env->img)
    {
        env->img = mlx_new_image(env->mlx, env->img_x, env->img_y);
        env->data = mlx_get_data_addr(env->img, &(env->bpp), &(env->sizeline), &(env->endian));
    }
    else
        ft_bzero(env->data, 4 * 1200 * 1200);
}

int print_square(t_env *env)
{
	env->frm.x = 100;
	while (env->frm.x < 1100)
	{
		env->frm.y = 100;
		while (env->frm.y < 1100)
		{
			ft_put_pixel_img(env, 0xFFFFFF);
			env->frm.y++;
		}
		env->frm.x++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	return(0);
}

void    ft_set_img_win(t_env *env)
{
    env->img_x = 1200;
    env->img_y = 1200;
}

int     ft_window(int argc, char **argv)
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
	raycast(env);
	//print_square(env);
	// ft_event(env);
    mlx_loop(env->mlx);
    return (0);
}

int     main(int argc, char **argv)
{
    ft_window(argc, argv);

    return (0);
}
