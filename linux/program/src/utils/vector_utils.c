/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/28 20:22:53 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/01/27 21:28:05 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

t_vec3	vec_gen(double x, double y, double z)
{
	t_vec3	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

int		vec_equal(t_vec3 a, t_vec3 b)
{
	if (a.x == b.x && a.y == b.y && a.z == b.z)
		return (0);
	return (1);
}


int		vec_parallel(t_vec3 a, t_vec3 b)
{
	// cauchy schwartz inequality
	// a . b = |a| * |b| * cos theta, but cos(0) = 1 so (a . b = |a| * |b|) if the angle between them is 0 (parallel)
	if (vec_dot(a, b) == vec_magnitude(a) * vec_magnitude(b))
		return (0);
	else
		return (1);
	a = vec_normalize(a);
	b = vec_normalize(b);
	if (a.x == b.x && a.y == b.y && a.z == b.z)
		return (0);
	if (a.x == -b.x && a.y == -b.y && a.z == -b.z)
		return (0);
	return (1);
}

int		vec_zero(t_vec3 v)
{
	if (v.x == 0 && v.y == 0 && v.z == 0)
		return (1);
	return (0);
}

/*
** Takes origin and direction as input.
** Returns 3 basis vectors relative to
** the world coordinate system.
*/

t_space	new_coordinate_space(t_vec3 origin, t_vec3 base_z)
{
	t_space	new;

	new.origin = origin;
	new.base_z = vec_normalize(base_z);
	new.base_x = vec_cross(base_z, vec_gen(0, 0, 1));
	if (vec_zero(new.base_x) == 1)
		new.base_x = vec_cross(base_z, vec_gen(0, 1, 0));
	new.base_x = vec_normalize(new.base_x);
	new.base_y = vec_cross(new.base_x, new.base_z);
	return (new);
}
