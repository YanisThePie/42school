/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 00:38:44 by yismail           #+#    #+#             */
/*   Updated: 2016/04/12 12:09:44 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "./minilibx_macos/mlx.h"
#include "fdf.h"

t_list const	*change_alt(t_list const *tmp)
{
	t_list			const *first;

	first = tmp;
	while (tmp != NULL)
	{
		if ((((t_stru *)tmp->content)->height) > 0)
			(((t_stru *)tmp->content)->height) =
			((((t_stru *)tmp->content)->height));
		tmp = tmp->next;
	}
	return (first);
}

int				ft_window(t_list const *lst)
{
	t_projdots		env;

	ft_set_event(&env);
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, 1200, 1200, "mlx 42");
	env.tmp = lst;
	ft_pixel_put(env.tmp, env.mlx, env.win, env);
	mlx_key_hook(env.win, my_key_funct, &env);
	mlx_loop(env.mlx);
	return (0);
}
