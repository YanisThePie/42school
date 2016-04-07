/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 00:38:44 by yismail           #+#    #+#             */
/*   Updated: 2016/04/07 05:24:27 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "./minilibx_macos/mlx.h"
#include "fdf.h"

int		ft_window (t_list const *lst)
{
	void			*mlx;
	void			*win;
	t_list const	*tmp;
	str_cmd			event;

	ft_set_event(&event);
	mlx = mlx_init ();
	win = mlx_new_window(mlx, 1200, 1200, "mlx 42");
	tmp = lst;
	ft_pixel_put(tmp, mlx, win, event);
	mlx_key_hook(win, my_key_funct, 0);
	mlx_loop(mlx);
	return(0);
}
