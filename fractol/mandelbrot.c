#include "fractol.h"

void complex_module (t_form *form, t_env *env)
{
	t_color clr;
	int clr_int;

	while (((form->z_r * form->z_r) + (form->z_i * form->z_i)) < 4
	&& form->i < form->iteration_max)
	{
		form->tmp = form->z_r;
		form->z_r = (form->z_r * form->z_r) -
		(form->z_i * form->z_i) + form->c_r;
		form->z_i = 2 * form->z_i * form->tmp + form->c_i;
		form->i += 1;
	}
	if (form->i == form->iteration_max)
		ft_put_pixel_img(env, form, 0x00000000);
	/**(unsigned int *)(env->data + form->y* env->sizeline
					  + 4* form->x) = 0x000000;
	*/
		
		else
	{
		clr.r = 0;
		clr.g = 0;
		clr.b = (form->i * 255 / form->iteration_max);
		clr_int = color_to_int (clr);
		ft_put_pixel_img(env, form, clr_int);
	}
}

void nested_loop(t_form *form, t_env *env)
{
	form->x = 0;
	while (form->x < form->image_x)
	{
		form->y = 0;
			while (form->y < form->image_y)
			{
				form->c_r = (form->x / form->zoom_x + form->x1);
				form->c_i = (form->y / form->zoom_y + form->y1);
				form->z_r = 0;
				form->z_i = 0;
				form->i = 0;
				complex_module(form, env);
				form->y++;
			}
			form->x++;
	}
}

int calcul_center (t_env *env, t_form *form)
{
	int coord_center_x;
	int coord_center_y;

	coord_center_x = (env->set.mse_h_x / 1200) * (form->x2 - form->x1) + form->x1;
	coord_center_y = (env->set.mse_h_y / 1200) * (form->y2 - form->y1) + form->y1;
	form->x1 = coord_center_x - (0.90) * (form->x2 - form->x1) / 2;
	form->x2 = coord_center_x + (0.90) * (form->x2 - form->x1) / 2;
    form->y1 = coord_center_y - (0.90) * (form->y2 - form->y1) / 2;
    form->y2 = coord_center_y + (0.90) * (form->y2 - form->y1) / 2;
	return(0);
}

int mandelbrot(t_env *env)
{
	t_form form;

	ft_bzero(&form, sizeof(t_form));
	if (env->set.mse_h_x == 0 && env->set.mse_h_y == 0)
	{
		form.x1 = -2.1;
		form.x2 = 0.6;
		form.y1 = -1.2;
		form.y2 = 1.2;
	}
	//else
		//calcul_center(env, &form);
	form.image_x = 1200;
	form.image_y = 1200;
	form.iteration_max = 50 + env->set.coef_iter;
	form.x = 0;
	form.y = 0;
	form.zoom_x = env->set.coef_zoom * form.image_x/(form.x2 - form.x1);
	form.zoom_y = env->set.coef_zoom * form.image_y/(form.y2 - form.y1);
	nested_loop(&form, env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	return(0);
}
