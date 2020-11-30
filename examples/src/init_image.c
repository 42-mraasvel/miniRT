/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_image.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 22:38:47 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/11/30 20:17:59 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "mlx.h"

int	create_trgb(int t, int r, int g, int b);

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	print_img_data(t_data img)
{
	printf("addr: |%p|\n", img.addr);
	printf("bits_per_pixel: |%d|\n", img.bits_per_pixel);
	printf("line_length: |%d|\n", img.line_length);
	printf("endian: |%d|\n", img.endian);
}

/*
** Writes color (changes pixel value) at offset.
** Offset formula explanation:
** 1. bits_per_pixel / 8 = byte size of the pixel. (if 32 bits per pixel size = 4, like an int).
** 2. line_length = total bytes in a window line ((max)x * 4 (if 32 bits per pixel)).
** 3. So (max)y * line_length = total bytes in the entire window.
** 4. This will give you the y coordinate, then you add the x coordinate, and you have the offset.
*/

void	my_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	fill_in_background(t_data *img, int x_max, int y_max, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < y_max)
	{
		x = 0;
		while (x < x_max)
		{
			my_pixel_put(img, x, y, color);
			x++;
		}
		y++;
	}
}

/*
** Input: the image to change
** start x and y coordinate
** side length of the square (size)
** color of the sides
*/

void	draw_square(t_data *img, int x, int y, int size, int color)
{
	int	i;
	int	j;

	i = x;
	j = y;
	while (j < size + y)
	{
		i = x;
		while (i < size + x)
		{
			my_pixel_put(img, i, j, color);
			i++;
		}
		j++;
	}
}

void	draw_triangle(t_data *img, int color, int x1, int y1, int x2, int y2, int x3, int y3)
{
	my_pixel_put(img, x1, y1, color);
	my_pixel_put(img, x2, y2, color);
	my_pixel_put(img, x3, y3, color);
}

void	init_image_example(void)
{
	void	*mlx;
	void	*mlx_window;
	t_data	img;
	int		x = 1280;
	int		y = 720;

	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, x, y, "Window Name");
	img.img = mlx_new_image(mlx, x, y);

	/*
	** After creating an image, we can call `mlx_get_data_addr`, we pass
	** `bits_per_pixel`, `line_length`, and `endian` by reference. These will
	** then be set accordingly for the *current* data address.
	*/
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	int color = create_trgb(255, 255, 0, 0);
	fill_in_background(&img, x, y, create_trgb(0, 255, 255, 255));
	draw_square(&img, 5, 5, 250, color);
	// draw_triangle(&img, color, 10, 10, 10, 30, 20, 20);
	mlx_put_image_to_window(mlx, mlx_window, img.img, 0, 0);
	mlx_loop(mlx);
	free(mlx);
}
