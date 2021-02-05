/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   compute_normals.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/04 13:23:14 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/05 11:31:14 by mraasvel      ########   odam.nl         */
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
	t_vec3		point_prime;
	double		t;

	cylinder = (t_cylinder*)object;
	t = vec_dot(cylinder->orient, vec_sub(point, cylinder->pos))
			/ vec_dot(cylinder->orient, cylinder->orient);
	point_prime = vec_add(
					cylinder->pos,
					vec_scalar(t, cylinder->orient));
	return (vec_normalized(vec_sub(point, point_prime)));
}

t_vec3	triangle_normal(t_vec3 point, void *object)
{
	(void)point;
	return (((t_triangle*)object)->norm);
}
