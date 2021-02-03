/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_operations3.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/03 18:30:19 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/03 21:25:55 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"
#include <stdio.h> // rm

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

void		print_vec(t_vec3 v)
{
	printf("(%.2f, %.2f, %.2f)\n", v.x, v.y, v.z);
}
