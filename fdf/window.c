#include "./libft/libft.h"
#include "./minilibx_macos/mlx.h"
#include "fdf.h"

int my_key_funct(int keycode, void *param)
{
	(void)param;
	ft_putstr("the key is ");
	ft_putnbr(keycode);
	ft_putchar('\n');
	if (keycode == 53)
		exit(EXIT_SUCCESS);
/*
	if (keycode = 24)
		event.zoom++;
	if (keycode = 27)
		event.zoom--;
*/
	return(0);
}

void ft_set_event(str_cmd *event)
{
	event->zoom = 1;
	event->alt = 1;
	event->move = 1;
	event->rotate = 1;
}

int ft_window (t_list const *lst)
{
	void	*mlx;
	void	*win;
	t_list const *tmp;
	str_cmd	event;

	ft_set_event(&event);
	mlx = mlx_init ();
	win = mlx_new_window(mlx, 1200, 1200, "mlx 42");
	tmp = lst;
	ft_pixel_put_h(tmp, mlx, win, event);
	mlx_key_hook(win, my_key_funct, 0);
	mlx_loop(mlx);
	return(0);
}

