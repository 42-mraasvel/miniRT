/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 22:38:47 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/15 21:04:20 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "mlx.h"
#include "minirt.h"

int	ft_strerror(int errnum)
{
	static const char	*error_table[] = {
		"Success",
		"Malloc Error",
		"Write Error" };

	if (printf("%s\n", error_table[errnum]) == -1)
		return (write_error);
	return (errnum);
}

int	call_draw_line(t_data *img)
{
	t_pair one, two;
	int	ret;

	one.x = 100; one.y = 250;
	two.x = 200; two.y = 500;
	ret = draw_line(one, two, img);
	if (ret != success)
		ft_strerror(ret);
	return (ret);
}

int	call_draw_triangle(t_data *img)
{
	t_triangle	triangle;
	int			ret;

	triangle.points[0].x = 300;
	triangle.points[0].y = 50;
	triangle.points[1].x = 100;
	triangle.points[1].y = 350;
	triangle.points[2].x = 1200;
	triangle.points[2].y = 500;
	draw_triangle(triangle, img);
	return (success);
}

typedef struct	s_vars
{
	void *mlx;
	void *win;
	t_pair coords;
}				t_vars;

int	mouse_motion(int keycode, t_vars *vars)
{
	printf("You moved the mouse! |%d|\n", keycode);
}

int	mouse_button(int keycode, t_vars *vars)
{
	if (keycode == 1)
	{
		printf("You pressed the left mouse button! |%d|\n", keycode);
	}
	else if (keycode == 3)
	{
		printf("You pressed the right mouse button!\n");
	}
	else
	{
		printf("You did something with the mouse. |%d|\n", keycode);
	}
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		printf("You pressed ESC.\nClosing MLX...");
		mlx_destroy_window(vars->mlx, vars->win);
		return (0);
	}
	printf("You pressed a key! |%d|\n", keycode);
	// mlx_destroy_window(vars->mlx, vars->win);
}

int	start_mlx(void)
{
	t_vars vars;
	void	*mlx;
	void	*mlx_window;
	t_data	img;

	vars.mlx = mlx_init();
	// vars.win = mlx_new_window(vars.mlx, 1280, 720, "Mini.maaRTen");
	// img.img = mlx_new_image(vars.mlx, 1280, 720);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// for (int i = 0; i < 1280; i++)
	// {
	// 	for (int j = 0; j < 720; j++)
	// 	{
	// 		ft_pixel_put(&img, i, j, 0x00000000);
	// 	}
	// }
	// call_draw_triangle(&img);
	// mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	// mlx_hook(vars.win, 4, 1L<<2, mouse_button, &vars);
	// mlx_hook(vars.win, 2, 1L<<0, key_hook, &vars);
	// mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
	return (success);
}

int	draw_square(t_data *img, int x, int y, int length, int color)
{
	for (int i = x; i < length + x; i++)
	{
		for (int j = y; j < length + y; j++)
			ft_pixel_put(img, i, j, color);
	}
}

int	move_square(int keycode, t_vars *vars)
{
	printf("keycode: %d\n", keycode);
	if (keycode == 100)
	{
		//move right
		vars->coords.x += 1;
	}
	else if (keycode == 97)
	{
		//move left
		if (vars->coords.x > 0)
			vars->coords.x -= 1;
	}
	else if (keycode == 119)
	{
		//move up
		if (vars->coords.y > 0)
			vars->coords.y -= 1;
	}
	else if (keycode == 115)
	{
		//move down
		vars->coords.y += 1;
	}
	else if (keycode == 101)
	{
		// move top right
		if (vars->coords.y > 0)
			vars->coords.y -= 1;
		vars->coords.x += 1;
	}
	else if (keycode == 113)
	{
		// move top left
		if (vars->coords.y > 0)
			vars->coords.y -= 1;
		if (vars->coords.x > 0)
			vars->coords.x -= 1;
	}
	return (0);
}

int	render_next_frame(int keycode, t_vars *vars)
{
	t_data	img;
	int	background_color = 0x00000000;
	int	color = 0x00FF0000;

	move_square(keycode, vars);
	img.img = mlx_new_image(vars->mlx, 1280, 720);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	for (int i = 0; i < 1280; i++)
	{
		for (int j = 0; j < 720; j++)
			ft_pixel_put(&img, i, j, background_color);
	}
	// draw_square(&img, coords.x, coords.y, 200, 0x00FF0000 + (int)((((double)cnt) * 5.20)));
	draw_square(&img, vars->coords.x, vars->coords.y, 200, color);
	// draw_square(&img, 50, 50, 200, color);
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
	free(img.img);
}

int	put_first_square(t_vars vars)
{
	t_data	img;

	img.img = mlx_new_image(vars.mlx, 200, 200);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	draw_square(&img, 0, 0, 200, 0x00FF00000);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	free(img.img);
}

int	test_loop(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1280, 720, "Mini.maaRTen");
	vars.coords.x = 0;
	vars.coords.y = 0;
	put_first_square(vars);
	mlx_hook(vars.win, 2, 1L<<0, render_next_frame, &vars);
	// mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	mlx_loop(vars.mlx);
	free(vars.mlx);
}

int	test_image(void)
{
	void	*mlx;
	void	*img;
	void	*win;
	char	*relative_path = "/home/maarten/Downloads/image.xpm";
	int	img_width;
	int	img_height;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1280, 720, "test");
	img = mlx_xpm_file_to_image(mlx, "/home/maarten/Downloads/image.xpm", &img_width, &img_height);
	printf("%p\n", img);
	printf("Width: %d\nHeight: %d\n", img_width, img_height);
	if (img == NULL)
		return (0);
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_put_image_to_window(mlx, win, img, 500, 100);
	mlx_put_image_to_window(mlx, win, img, 900, 200);
	mlx_loop(mlx);
	mlx_destroy_image(mlx, img);
	// mlx_destroy_window(mlx, win);
	mlx_destroy_display(mlx);
	free(mlx);
	return (0);
}

int	main(void)
{
	test_image();
	return (0);
}
