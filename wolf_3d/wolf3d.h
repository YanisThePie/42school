#ifndef WOLF3D_H
# define WOLF3D_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "./libft/libft.h"
# include <math.h>
# include "./minilibx_macos/mlx.h"
# include <unistd.h>
#include <stdio.h>

typedef struct      s_stru
{
    double             coord_x;
    double             coord_y;
    double            val_int;
}                   t_stru;

typedef struct      s_setplayer
{
    double			posX;
    double			posY;
	double			dirX;
	double			dirY;
	double			planeX;
	double			planeY;
}                   t_setplayer;

typedef struct      s_form
{
	double				sizemap_x;
	double				sizemap_y;
    double          time;
    double          oldTime;
    double          cameraX;
    double          rayPosX;
    double          rayPosY;
	double			rayDirX;
	double			rayDirY;
	double            mapX;
	double				mapY;
	double			sideDistX;
	double			sideDistY;
	double			deltaDistX;
	double			deltaDistY;
	double			perpWallDist;
    double				stepX;
	double				stepY;
	double				hit;
	double				side;
  double             x;
  double             y;
    double             i;
}                   t_form;

typedef struct		s_data
{
	double         lineHeight;
	double			drawStart;
	double			drawEnd;
}					t_data;

typedef struct      s_env
{
    void            *mlx;
    void            *win;
    void            *img;
    char            *data;
    char            *name;
    int             bpp;
    int             sizeline;
    int             oct;
    int             endian;
	int				img_x;
	int				img_y;
	char			*worldMap[99];
    t_setplayer     player;
	t_form          frm;
	t_data			draw;
}                   t_env;

int     ft_parsing(int argc, char **argv, t_env *env);
int		raycast (t_env *env);
#endif
