/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   compute_normals.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/04 13:23:14 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/04 20:29:18 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"
#include "objects.h"
#include "raytracing.h"

t_vec3	sphere_normal(t_vec3 point, void *object)
{
	return (vec_normalized(vec_sub(point, ((t_sphere*)object)->pos)));
}

t_vec3	plane_normal(t_vec3 point, void *object)
{
	(void)point;
	return (((t_plane*)object)->norm);
}

t_vec3	square_normal(t_vec3 point, void *object)
{
	(void)point;
	return (((t_square*)object)->norm);
}

/*
** Calculate point P' on cylinder line
** perpendicular to the intersection point.
** Normal = P - P'
*/

t_vec3	cylinder_normal(t_vec3 point, void *object)
{
	t_cylinder	*cylinder;
	t_ray		cyl_line;
	t_vec3		point_prime;

	cylinder = (t_cylinder*)object;
	cyl_line.dir = cylinder->orient;
	cyl_line.origin = cylinder->pos;
	cyl_line.t = intersect_plane_wrap(cyl_line, cyl_line.dir, point);
	point_prime = vec_add(
					cyl_line.origin,
					vec_scalar(cyl_line.t, cyl_line.dir));
	return (vec_normalized(vec_sub(point, point_prime)));
}

t_vec3	triangle_normal(t_vec3 point, void *object)
{
	(void)point;
	return (((t_triangle*)object)->norm);
}
