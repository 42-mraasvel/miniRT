/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/16 22:00:54 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/28 16:20:55 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../include/minirt.h"
#include "libft.h"
#include "scene.h"
// #include "minirt.h"

int	free_boys(void *mlx_ptr)
{
	free(mlx_ptr);
	return (0);
}

int	gen_color(int red, int green, int blue)
{
	return ((red << 16) + (green << 8) + blue);
}

void	put_pixel_to_image(t_img img, int x, int y, int color)
{
	unsigned int	*addr;

	addr = (unsigned int *)(img.addr + (y * img.size_line) + x * (img.bpp / 8));
	*addr = color;
}

int	hook_event(int keycode, t_mlx *data)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit(1);
	}
	printf("Keycode: %d\n", keycode);
}

int	window_x(int keycode, t_mlx *data)
{
	printf("WINDOW IS CLOSED!\n\n");
	return (0);
}

void	init_image(t_img *img, t_mlx data, int x, int y)
{
	img->img_ptr = mlx_new_image(data.mlx_ptr, x, y);
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bpp, &img->size_line, &img->endian);
}

void	fill_image_randomly(t_img *img, int x, int y)
{
	size_t	i;
	size_t	j;
	int		color;
	int		r;
	int		g;

	i = 0;
	r = 0;
	while (i < y)
	{
		if (i % (y / 255 + 1) == 0)
			if (r < 255)
				r++;
		j = 0;
		g = 0;
		while (j < x)
		{
			if (j % (y / 255 + 1) == 0)
			{
				if (g < 255)
					g++;
			}
			color =  gen_color(r, g, 0);
			put_pixel_to_image(*img, j, i, color);
			j++;
		}
		i++;
	}
}

int	change_r(int color, int r)
{
	int	r_mask;

	r_mask = -1 - (255 << 16);
	color = (color & r_mask) + (r << 16);
	return (color);
}
int	change_g(int color, int g)
{
	int	g_mask;

	g_mask = -1 - (255 << 8);
	color = (color & g_mask) + (g << 8);
	return (color);
}
int	change_b(int color, int b)
{
	int	b_mask;

	b_mask = -1 - (255);
	color = (color & b_mask) + b;
	return (color);
}

void	fill_window(t_mlx data)
{
	size_t	i;
	size_t	j;
	int		color;
	int		r, g;
	int		m;
	int		m2;

	i = 0;
	m = Y_WIN / 255;
	m2 = X_WIN / 255;
	color = 0;
	r = g = 0;
	while(i < Y_WIN)
	{
		j = 0;
		if (i % m == 0)
		{
			color = change_r(color, r);
			if (r < 255)
				r++;
		}
		g = 0;
		while (j < X_WIN)
		{
			if (j % m2 == 0)
			{
				color = change_g(color, g);
				if (g < 255)
					g++;
			}
			mlx_pixel_put(data.mlx_ptr, data.win_ptr, j, i, color);
			j++;
		}
		i++;
	}
}

int	mlx_test(t_mlx data)
{
	t_img	img;
	int		x, y;

	x = X_WIN;
	y = Y_WIN;
	init_image(&img, data, x, y);
	fill_image_randomly(&img, x, y);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img.img_ptr, 0, 0);
	mlx_destroy_image(data.mlx_ptr, img.img_ptr);
	return (success);
}

int	mlx_engine(t_mlx *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (error);
	int x, y;
	int ret = mlx_get_screen_size(data->mlx_ptr, &x, &y);
	printf("ret: %d\n%d %d\n", ret, x, y);
	data->win_ptr = mlx_new_window(data->mlx_ptr, X_WIN, Y_WIN, "Mini Window");
	if (data->win_ptr == NULL)
	{
		free_boys(data->mlx_ptr);
		return (error);
	}
	return (success);
}

t_point	gen_point(double x, double y, double z)
{
	t_point	p;

	p.x = x;
	p.y = y;
	p.z = z;
	return (p);
}

void	set_scene_data(t_scene *scene)
{
	scene->camera.position = gen_point(0, 0, -1);
	scene->camera.orientation_vector = gen_point(0, 0, 1);
	scene->camera.fov = atan(100.0) * (180 / M_PI);
	scene->screen.x = X_WIN;
	scene->screen.y = Y_WIN;
}

int	main(void)
{
	t_mlx	data;
	t_scene	scene;

	if (mlx_engine(&data) == error)
		return (0);
	mlx_test(data);
	mlx_hook(data.win_ptr, 2, 1L<<0, hook_event, &data);
	set_scene_data(&scene);
	printf("%f\n", scene.camera.fov);
	if (render_scene(scene, data) == error)
	{
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
		return (0);
	}
	mlx_loop(data.mlx_ptr);
	if (data.mlx_ptr != NULL)
		mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	return (0);
}
