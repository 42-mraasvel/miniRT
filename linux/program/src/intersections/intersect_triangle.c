/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersect_triangle.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/11 15:43:00 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/01/11 16:03:20 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h" // rm


static double	calculate_b(t_vec3 one, t_vec3 two, t_vec3 three, t_vec3 p)
{
	double	constant;
	double	denominator;

	constant = -one.x * (three.y - one.y) + (one.y - p.y) * (three.x - one.x) + p.x * (three.y - one.y);
	denominator = (two.x - one.x) * (three.y - one.y) - (two.y - one.y) * (three.x - one.x);
	return (constant / denominator);
}

static double	calculate_c(t_triangle triangle, t_vec3 p, double b)
{
	double	c;
	t_vec3	one;
	t_vec3	two;
	t_vec3	three;

	one = triangle.point_1;
	two = triangle.point_2;
	three = triangle.point_3;
	c = (p.y - one.y - b * (two.y - one.y)) / (three.y - one.y);
	return (c);
}

/*
** 1. Find plane intersection.
** 2. Find if intersection point lies inside the triangle using barycentric coordinates.
** A = Point1
** B = Point2
** C = Point3
** P = intersection point
** b = (-Ax(Cy - Ay) + (Ay - Py)(Cx - Ax) + Px(Cy - Ay)) / ((Bx - Ax)(Cy - Ay) - (By - Ay)(Cx - Ax))
** c = (Py - Ay - b(By - Ay)) / (Cy - Ay)
*/

static double	intersect_triangle(t_vec3 origin, t_vec3 direction, t_triangle triangle)
{
	t_vec3	normal;
	t_vec3	intersection_point;
	double	t;
	double	b;
	double	c;

	normal = vec_normalize(vec_cross(vec_sub(triangle.point_2, triangle.point_1), vec_sub(triangle.point_3, triangle.point_1)));
	t = intersect_plane(origin, direction, triangle.point_1, normal);
	if (t < 0)
		return (-1);
	intersection_point = vec_add(origin, vec_scalar(direction, t));
	b = calculate_b(triangle.point_1, triangle.point_2, triangle.point_3, intersection_point);
	c = calculate_c(triangle, intersection_point, b);
	if (b < 0 || c < 0 || b > 1 || c > 1 || b + c > 1)
		return (-1);
	return (t);
}

static t_vec3	calculate_triangle_normal(t_triangle triangle)
{
	return (vec_normalize(vec_cross(vec_sub(triangle.point_2, triangle.point_1), vec_sub(triangle.point_3, triangle.point_1))));
}

void			intersect_triangles(t_vec3 origin, t_vec3 direction,
		t_vect *triangles, t_intersection_data *data)
{
	size_t		i;
	t_triangle	*table;
	double		intersection;

	i = 0;
	table = (t_sphere*)triangles->table;
	while (i < triangles->nmemb)
	{
		intersection = intersect_triangle(origin, direction, table[i]);
		if (intersection >= 0.0)
		{
			if (data->t < 0.0)
				data->t = intersection;
			else
				data->t = ft_fmin(data->t, intersection);
			if (data->t == intersection)
			{
				data->color = table[i].color;
				data->intersection_point = vec_add(origin, vec_scalar(direction, data->t));
				data->surface_normal = calculate_triangle_normal(table[i]);
			}
		}
		i++;
	}
}
