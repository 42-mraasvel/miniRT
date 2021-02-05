/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_operations3.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/03 18:30:19 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/04 23:19:44 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_cspace	new_space(t_vec3 origin, t_vec3 forward)
{
	t_cspace	space;
	t_vec3		y_axis;

	space.forward = forward;
	space.origin = origin;
	y_axis = vec_gen(0, 1, 0);
	if (vec_parallel(forward, y_axis))
		space.right = vec_cross(vec_gen(0, 0, -1), forward);
	else
		space.right = vec_cross(y_axis, forward);
	vec_normalize(&space.right);
	space.up = vec_cross(forward, space.right);
	return (space);
}

float		vec_sqrd(t_vec3 v)
{
	return (vec_dot(v, v));
}

void		vec_invert(t_vec3 *v)
{
	v->x *= -1;
	v->y *= -1;
	v->z *= -1;
}

t_vec3		vec_inverted(t_vec3 v)
{
	v.x *= -1;
	v.y *= -1;
	v.z *= -1;
	return (v);
}
