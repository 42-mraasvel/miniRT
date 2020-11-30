/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/29 19:45:58 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/11/30 10:36:01 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "math.h"
#include "mlx.h"
#include "bresenham.h"

void	my_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_size + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	init_image(void)
{
	void	*mlx;
	void	*mlx_window;
	t_data	img;
	int		x = 1280;
	int		y = 720;

	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, x, y, "MLX Window");
	img.img = mlx_new_image(mlx, x, y);

	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_size, &img.endian);
	my_pixel_put(&img, 5, 5, 0x00FF00000);
	mlx_put_image_to_window(mlx, mlx_window, img.img, 0, 0);
	mlx_loop(mlx);
	free(mlx);
}

double	*get_pixel_coordinates(int x0, int y0, int x1, int y1)
{
	double	*coords;
	double	slope;
	int		i;

	coords = (double*)malloc(abs(x1 - x0 + 1) * sizeof(double));
	if (coords == NULL)
		return (NULL);
	slope = (double)(y1 - y0) / (double)(x1 - x0);
	printf("slope: %f\n", slope);
	i = 0;
	while (i < (x1 - x0 + 1))
	{
		coords[i] = (slope * i) + y0;
		i++;
	}
	return (coords);
}

void	print_y_coords(double *coords, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("%2d: %f\n", i + 1, coords[i]);
		i++;
	}
	printf("size: %d\n", size);
}

int	main(void)
{
	int x0;
	int	y0;
	int	x1;
	int	y1;

	scanf("%d %d", &x0, &y0);
	scanf("%d %d", &x1, &y1);
	dda_line_drawing(x0, y0, x1, y1);
	return (0);
}
