/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersect_triangle.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/11 15:43:00 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/01/30 12:44:06 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h" // rm

static double	point_line(t_vec3 edge, t_vec3 normal, t_vec3 point_vector)
{
	return (vec_dot(normal, vec_cross(edge, point_vector)));
}

static int		point_in_triangle(t_triangle t, t_vec3 point, t_vec3 normal)
{
	t_double	t0;
	t_double	t1;
	t_double	t2;

	t0.value = point_line(vec_sub(t.point_2, t.point_1), normal, vec_sub(point, t.point_1));
	t1.value = point_line(vec_sub(t.point_3, t.point_2), normal, vec_sub(point, t.point_2));
	t2.value = point_line(vec_sub(t.point_1, t.point_3), normal, vec_sub(point, t.point_3));
	if (t0.bits.sign == t1.bits.sign && t0.bits.sign == t2.bits.sign)
		return (true);
	return (false);
}

/*
** First plane intersection test
** Then see if point lies inside the triangle
** This is done by checking if the point is either
** to the left or to the right of all edges
*/

static double	intersect_triangle(t_vec3 origin, t_vec3 direction, t_triangle triangle)
{
	t_vec3	normal;
	t_vec3	point;
	double	t;

	normal = vec_normalize(vec_cross(vec_sub(triangle.point_2, triangle.point_1), vec_sub(triangle.point_3, triangle.point_1)));
	t = intersect_plane(origin, direction, triangle.point_1, normal);
	if (t < 0)
		return (-1);
	point = vec_add(origin, vec_scalar(direction, t));
	if (!point_in_triangle(triangle, point, normal))
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
	table = (t_triangle*)triangles->table;
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
