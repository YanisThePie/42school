int ft_window()
{
	t_env env;

	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, 1200, 1200, "fractol");
	
}


int main (int *argc, char **argv)
{
	if (argc != 2)
		exit(EXIT_FAILURE);
	ft_window();
	return (0);
}
