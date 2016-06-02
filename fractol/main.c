/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 16:56:53 by yismail           #+#    #+#             */
/*   Updated: 2016/05/24 15:15:27 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		choose_fract(t_env *env)
{
	if (!strcmp(env->what_fract, "Mandelbrot") || env->set.key_c == 1)
	{
		mandelbrot(env);
		instru_window(env);
		return (0);
	}
	if (!strcmp(env->what_fract, "Julia") || env->set.key_c == 2)
	{
		julia(env);
		instru_window(env);
		return (0);
	}
	if (!strcmp(env->what_fract, "Julia_atomos") || env->set.key_c == 3)
	{
		julia_atomos(env);
		instru_window(env);
		return (0);
	}
	else
	{
		ft_putstr("Mandelbrot\nJulia\nJulia_Atomos\n");
		(exit(EXIT_FAILURE));
	}
	return (0);
}

void	ft_set(t_env *env)
{
	env->set.img_x = 1200;
	env->set.img_y = 1200;
	env->set.coef_iter = 0;
	env->frm.image_x = 1200;
	env->frm.image_y = 1200;
	env->set.coef_zoom = 1;
	env->set.mse_h_x = 0.00;
	env->set.mse_h_y = 0.00;
	env->set.key_zm = 0;
	env->set.pos_x = 0;
	env->set.pos_y = 0;
	env->set.key_c = 0;
}

int		instru_window(t_env *env)
{
	int i;
	int j;

	j = 0;
	i = 250;
	while (j < 200)
	{
		mlx_pixel_put(env->mlx, env->win, i, j, 0xe0e0e0);
		j++;
	}
	while (i > 0)
	{
		mlx_pixel_put(env->mlx, env->win, i, j, 0xe0e0e0);
		i--;
	}
	mlx_string_put(env->mlx, env->win, 20, 20, 16777215, "Zoom = left-click");
	mlx_string_put(env->mlx, env->win, 20, 40, 16777215, "iterations = +/-");
	mlx_string_put(env->mlx, env->win, 20, 60, 16777215, "Restore image = R");
	mlx_string_put(env->mlx, env->win, 20, 80, 16777215, "exit = Esc");
	mlx_string_put(env->mlx, env->win, 1100, 60,
	16777215, ft_itoa(env->frm.iteration_max));
	return (0);
}

int		ft_window(char *what_fract)
{
	t_env *env;

	env = (t_env*)malloc(sizeof(t_env));
	env->mlx = mlx_init();
	env->img = NULL;
	env->data = NULL;
	env->win = mlx_new_window(env->mlx, 1200, 1200, "fractol");
	ft_set(env);
	ft_new_img(env);
	env->oct = (env->bpp / 8);
	env->what_fract = what_fract;
	choose_fract(env);
	ft_event(env);
	mlx_loop(env->mlx);
	return (0);
}

int		main(int argc, char **argv)
{
	(void)*argv;
	if (argc != 2)
		exit(EXIT_FAILURE);
	ft_window(argv[1]);
	return (0);
}
