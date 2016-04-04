#include "fdf.h"


void ligne_n1(bresen br, void *mlx, void *win)
{
	br.cumul = br.dx / 2 ;
	br.i = 1;
	while (br.i <= br.dx)
	{
		br.x += br.xinc ;
		br.cumul += br.dy ;
		if ( br.cumul >= br.dx )
		{
			br.cumul -= br.dx ;
			br.y += br.yinc ;
		}
		mlx_pixel_put(mlx, win, br.x, br.y, 0x00ffffff);
		br.i++;
	}
}

void ligne_n2(bresen br, void *mlx, void *win)
{
	br.cumul = br.dy / 2 ;
	br.i = 1;
	while (br.i <= br.dy)
	{
		br.y += br.yinc ;
		br.cumul += br.dx ;
		if ( br.cumul >= br.dy )
		{
			br.cumul -= br.dy ;
			br.x += br.xinc ;
		}
		mlx_pixel_put(mlx, win, br.x, br.y, 0x000000FF);
		br.i++;
	}
}


void ligne(proj_dots spc, void *mlx, void *win) 
{
	bresen br;

	br.x = spc.x0;
	br.y = spc.y0;
	br.dx = spc.x1 - spc.x0;
	br.dy = spc.y1 - spc.y0;
	br.xinc = ( br.dx > 0 ) ? 1 : -1 ;
	br.yinc = ( br.dy > 0 ) ? 1 : -1 ;
	br.dx = abs(br.dx);
	br.dy = abs(br.dy);
	mlx_pixel_put(mlx, win, br.x, br.y, 0x0000FF00);
	if (br.dx > br.dy) 
		ligne_n1(br, mlx, win);
    else 
		ligne_n2(br, mlx, win);
}
