#ifndef FRACTOL_H
# define FRACTOL_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "./libft/libft.h"
# include <math.h>
# include "./minilibx_macos/mlx.h"
# include <unistd.h>

typedef struct  s_set
{
	int		img_x;
	int		img_y;
	int		coef_iter;
	double	coef_zoom;
	double	mse_h_x;
	double	mse_h_y;
	int		key_zm;
}			t_set;

typedef struct  s_form
{
    double x1;
    double x2;
    double y1;
    double y2;
    int image_x;
    int image_y;
    int iteration_max;
    double zoom_x;
    double zoom_y;
    int x;
    int y;
    double c_r;
    double c_i;
    double z_r;
    double z_i;
    int i;
    double tmp;

}               t_form;

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*data;
	char	*name;
	int		bpp;
	int		sizeline;
	int		oct;
	int		endian;
	t_set	set;
	t_form	frm;
	char    *what_fract;
	
}				t_env;

void ft_set(t_env *env);
int mandelbrot(t_env *env);
int ft_event(t_env *env);
void ft_new_img(t_env *env);
void ft_put_pixel_img(t_env *env, int clr_int);
int choose_fract(t_env *env);
int instru_window(t_env *env);
void ft_put_pixel_img(t_env *env, int clr_int);
void ft_color(t_env *env);
int julia(t_env *env);

#endif
