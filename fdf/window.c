/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 00:38:44 by yismail           #+#    #+#             */
/*   Updated: 2016/04/07 09:06:59 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "./minilibx_macos/mlx.h"
#include "fdf.h"

int		ft_window (t_list const *lst)
{
	proj_dots		env;
	
	ft_set_event(&env);
	env.mlx = mlx_init ();
	env.win = mlx_new_window(env.mlx, 1200, 1200, "mlx 42");
	env.tmp = lst;
	ft_pixel_put(env.tmp, env.mlx, env.win, env);
	mlx_key_hook(env.win, my_key_funct, &env);
	//mlx_loop(mlx);
	//mlx_loop_hook(mlx, (void*)ft_pixel_put, &env);
	mlx_loop(env.mlx);
	return(0);
}
