/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_triangle.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/30 21:31:39 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/01 10:40:00 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minirt.h"

static int	ft_max(int a, int b)
{
	return (a  > b ? a : b);
}

static int	ft_min(int a, int b)
{
	return (a < b ? a : b);
}

t_triangle	set_triangle_information(t_triangle triangle)
{

	triangle.vert_points.x = ft_max(triangle.points[0].y, triangle.points[1].y);
	triangle.vert_points.x = ft_max(triangle.vert_points.x, triangle.points[2].y);
	triangle.vert_points.y = ft_min(triangle.points[0].y, triangle.points[1].y);
	triangle.vert_points.y = ft_min(triangle.vert_points.y, triangle.points[2].y);
	return (triangle);
}

int	free_triangle(t_triangle triangle, t_errnum type, int location)
{
	if (type == success)
	{
		free(triangle.lines[0].coordinates);
		free(triangle.lines[1].coordinates);
		free(triangle.lines[2].coordinates);
		free(triangle.hori_points);
	}
	else
	{
		if (location > 0)
			free(triangle.lines[0].coordinates);
		if (location > 1)
			free(triangle.lines[1].coordinates);
		if (location > 2)
			free(triangle.lines[2].coordinates);
		if (location > 3)
			free(triangle.hori_points);
	}
	return (type);
}

int	set_min_max_values(t_pair vert_points, t_pair *hori_points, t_line line)
{
	
}

/*
** size: y_high - y_low
*/

int	set_triangle_horizontal_points(t_triangle *triangle)
{
	int	height;

	height = triangle->vert_points.x - triangle->vert_points.y + 1;
	triangle->hori_points = (t_pair*)calloc(height, sizeof(t_pair)); // set to ft_calloc
	if (triangle->hori_points == NULL)
		return (malloc_error);
	set_min_max_values(triangle->vert_points, triangle->hori_points, triangle->lines[0]);
	set_min_max_values(triangle->vert_points, triangle->hori_points, triangle->lines[1]);
	set_min_max_values(triangle->vert_points, triangle->hori_points, triangle->lines[2]);
	return (success);
}

int	draw_triangle(t_triangle triangle, t_data *img)
{
	triangle.lines[0] = generate_line(triangle.points[0].x, triangle.points[0].y, triangle.points[1].x, triangle.points[1].y);
	if (triangle.lines[0].coordinates == NULL)
		return (malloc_error);
	triangle.lines[1] = generate_line(triangle.points[0].x, triangle.points[0].y, triangle.points[2].x, triangle.points[2].y);
	if (triangle.lines[1].coordinates == NULL)
		return (free_triangle(triangle, malloc_error, 1));
	triangle.lines[2] = generate_line(triangle.points[1].x, triangle.points[1].y, triangle.points[2].x, triangle.points[2].y);
	if (triangle.lines[2].coordinates == NULL)
		return (free_triangle(triangle, malloc_error, 2));
	triangle = set_triangle_information(triangle);
	if (set_triangle_horizontal_points(&triangle) == malloc_error)
		return (free_triangle(triangle, malloc_error, 3));
	return (free_triangle(triangle, success, 0));
}
