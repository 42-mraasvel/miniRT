/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_triangle.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/30 21:31:39 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/11/30 21:49:36 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minirt.h"

int	draw_triangle(t_triangle triangle, t_data *img)
{
	triangle.lines[0] = generate_line(triangle.points[0].x, triangle.points[0].y, triangle.points[1].x, triangle.points[1].y);
	if (triangle.lines[0].coordinates == NULL)
		return (malloc_error);
	triangle.lines[1] = generate_line(triangle.points[0].x, triangle.points[0].y, triangle.points[2].x, triangle.points[2].y);
	if (triangle.lines[0].coordinates == NULL)
	{
		free(triangle.lines[0].coordinates);
		return (malloc_error);
	}
	triangle.lines[2] = generate_line(triangle.points[1].x, triangle.points[1].y, triangle.points[2].x, triangle.points[2].y);
	if (triangle.lines[0].coordinates == NULL)
	{
		free(triangle.lines[0].coordinates);
		free(triangle.lines[1].coordinates);
		return (malloc_error);
	}
	draw_line(triangle.points[0], triangle.points[1], img);
	draw_line(triangle.points[0], triangle.points[2], img);
	draw_line(triangle.points[1], triangle.points[2], img);
	free(triangle.lines[0].coordinates);
	free(triangle.lines[1].coordinates);
	free(triangle.lines[2].coordinates);
	return (success);
}
