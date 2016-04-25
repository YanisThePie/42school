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

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*data;
	int		bpp;
	int		sizeline;
	int		endian;
	
}				t_env;

typedef struct	s_form
{
	double x1;
	double x2;
	double y1;
	double y2;
	int image_x;
	int image_y;
	int iteration_max;
	int zoom_x;
	int zoom_y;
	int x;
	int y;
	int c_r;
	int c_i;
	int z_r;
	int z_i;
	int i;
	int tmp;
	
}				t_form;

int mandelbrot(t_env *env);


#endif
