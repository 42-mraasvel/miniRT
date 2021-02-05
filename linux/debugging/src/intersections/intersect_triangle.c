/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersect_triangle.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/03 22:30:45 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/05 13:45:55 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include "minirt.h"
#include "raytracing.h"
#include "ft_double.h"

static double	point_line(t_vec3 edge, t_vec3 normal, t_vec3 point_vector)
{
	return (vec_dot(normal, vec_cross(edge, point_vector)));
}

/*
** Dot product between normal
** and sides of the triangle
** to determine whether point
** lies to the left or right of a side
** If to the right or left of all sides,
** the point is inside of the triangle
*/

static t_bool	point_in_triangle(t_triangle *t, t_vec3 point, t_vec3 normal)
{
	t_double	t0;
	t_double	t1;
	t_double	t2;

	t0.value = point_line(
				vec_sub(t->point2, t->point1),
				normal,
				vec_sub(point, t->point1));
	t1.value = point_line(
				vec_sub(t->point3, t->point2),
				normal,
				vec_sub(point, t->point2));
	t2.value = point_line(
				vec_sub(t->point1, t->point3),
				normal,
				vec_sub(point, t->point3));
	if (t0.bits.sign == t1.bits.sign && t0.bits.sign == t2.bits.sign)
		return (true);
	return (false);
}

/*
** 1. Intersect with plane
** triangle lies on
** 2. Check if point lies
** in triangle
*/

t_bool			intersect_triangle(t_ray *ray, void *object)
{
	t_triangle	*triangle;
	double		t;
	t_vec3		intersect;

	triangle = (t_triangle*)object;
	t = intersect_plane_wrap(*ray, triangle->norm, triangle->point1);
	if (t <= 0)
		return (false);
	intersect = vec_add(ray->origin, vec_scalar(t, ray->dir));
	if (point_in_triangle(triangle, intersect, triangle->norm) == false)
		return (false);
	return (update_ray(ray, t, object));
}
