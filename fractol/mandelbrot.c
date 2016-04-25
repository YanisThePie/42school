#include "fractol.h"

void complex_module (t_form *form, t_env *env)
{
	while (((form->z_r * form->z_r) + (form->z_i * form->z_i)) < 4
	&& form->i < form->iteration_max)
	{
		form->tmp = form->z_r;
		form->z_r = (form->z_r * form->z_r) -
		(form->z_i * form->z_i) + form->c_r;
		form->z_i = (2 * form->z_i * form->tmp + form->c_i);
		form->i = form->i + 1;
	}
	if (form->i == form->iteration_max)
		*(unsigned int *)(env->data + form->y* env->sizeline
		+ 4* form->x) = 0xff0000;
	else
		*(unsigned int *)(env->data + form->y* env->sizeline
						  + 4* form->x) = 0xffffff;
		
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

int mandelbrot(t_env *env)
{
	t_form form;

	form.x1 = -2.1;
	form.x2 = 0.6;
	form.y1 = -1.2;
	form.y2 = 1.2;
	form.image_x = 270;
	form.image_y = 240;
	form.iteration_max = 50;
	form.x = 0;
	form.y = 0;
	form.zoom_x = form.image_x/(form.x2 - form.x1);
	form.zoom_y = form.image_y/(form.y2 - form.y1);
	nested_loop(&form, env);
	return(0);
}
