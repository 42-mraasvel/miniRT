/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/28 20:22:53 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/29 22:39:20 by mraasvel      ########   odam.nl         */
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

/*
** Takes origin and direction as input.
** Returns 3 basis vectors relative to
** the world coordinate system.
*/

t_space	new_coordinate_space(t_vec3 origin, t_vec3 base_z)
{
	t_space	new;
	t_vec3	y;

	new.origin = origin;
	new.base_z = base_z;
	y = vec_gen(0, 1, 0);
	if (vec_equal(base_z, y) == 0)
		new.base_x = vec_cross(base_z, vec_gen(0, 0, 1));
	else
		new.base_x = vec_cross(base_z, y);
	new.base_y = vec_cross(new.base_x, new.base_z);
	return (new);
}
