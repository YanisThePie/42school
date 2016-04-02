#include "fdf.h"



void ligne(int xi,int yi,int xf,int yf, void *mlx, void *win) 
{
	int dx,dy,i,xinc,yinc,cumul,x,y ;
	x = xi ;
	y = yi ;
	dx = xf - xi ;
	dy = yf - yi ;
	xinc = ( dx > 0 ) ? 1 : -1 ;
	yinc = ( dy > 0 ) ? 1 : -1 ;
	dx = abs(dx) ;
	dy = abs(dy) ;
	mlx_pixel_put(mlx, win, x, y, 0x00ffffff);
	if ( dx > dy ) {
		cumul = dx / 2 ;
		for ( i = 1 ; i <= dx ; i++ ) {
			x += xinc ;
			cumul += dy ;
			if ( cumul >= dx ) {
				cumul -= dx ;
				y += yinc ; }
			mlx_pixel_put(mlx, win, x, y, 0x00ffffff); } }
    else {
		cumul = dy / 2 ;
		for ( i = 1 ; i <= dy ; i++ ) {
			y += yinc ;
			cumul += dx ;
			if ( cumul >= dy ) {
				cumul -= dy ;
				x += xinc ; }
			mlx_pixel_put(mlx, win, x, y, 0x00ffffff); ; } }
}
