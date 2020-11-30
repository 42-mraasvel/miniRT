/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_line.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/30 18:32:13 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/11/30 21:01:21 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include <stdio.h> // rm
#include "mlx.h"
#include "minirt.h"

// test malloc failure
// #define malloc(x) NULL

static int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

static void	generate_line_coordinates(t_line line)
{
	double	x;
	double	y;
	double	x_inc;
	double	y_inc;

	x_inc = (double)line.delta_x / (double)(line.size - 1);
	y_inc = (double)line.delta_y / (double)(line.size - 1);
	x = (double)line.start.x;
	y = (double)line.start.y;
	while(line.size >= 0)
	{
		(*line.coordinates).x = (int)round(x);
		(*line.coordinates).y = (int)round(y);
		(line.coordinates)++;
		x += x_inc;
		y += y_inc;
		line.size--;
	}
}

static void	print_line_coordinates(t_line line)
{
	int	i;

	i = 0;
	printf("%3c | %3c\n", 'x', 'y');
	while (i < line.size)
	{
		printf("%3d | %3d\n", line.coordinates[i].x, line.coordinates[i].y);
		i++;
	}
}

t_line	generate_line(int x0, int y0, int x1, int y1)
{
	t_line	line;

	line.start.x = x0;
	line.start.y = y0;
	line.end.x = x1;
	line.end.y = y1;
	line.delta_x = x1 - x0;
	line.delta_y = y1 - y0;
	line.size = ft_abs(line.delta_x) > ft_abs(line.delta_y) ? ft_abs(line.delta_x) : ft_abs(line.delta_y);
	line.size++;
	line.coordinates = (t_pair*)malloc(line.size * sizeof(t_pair));
	if (line.coordinates == NULL)
		return (line);
	generate_line_coordinates(line);
	return (line);
}

int	put_line_to_window(t_line line, t_data *img)
{
	int	i;

	i = 0;
	while (i < line.size)
	{
		ft_pixel_put(img, line.coordinates[i].x, line.coordinates[i].y, 0x00FF0000);
		i++;
	}
	return (success);
}

int	draw_line(t_pair one, t_pair two, t_data *img)
{
	t_line	line;

	line = generate_line(one.x, one.y, two.x, two.y);
	if (line.coordinates == NULL)
		return (malloc_error);
	print_line_coordinates(line);
	put_line_to_window(line, img);
	free(line.coordinates);
	return (success);
}
