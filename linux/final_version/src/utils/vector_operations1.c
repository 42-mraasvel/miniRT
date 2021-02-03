/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_operations1.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/03 16:19:01 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/03 16:35:07 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_vec3	vec_gen(float x, float y, float z)
{
	return ((t_vec3) {
		.x = x,
		.y = y,
		.z = z});
}

float	vec_dot(t_vec3 a, t_vec3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

/*
** Determinant:
** |i  j  k |
** |ax ay az|
** |bx by bz|
** t_vec3 (i, -j, k)
*/

t_vec3	vec_cross(t_vec3 a, t_vec3 b)
{
	t_vec3	axb;

	axb.x = a.y * b.z - a.z * b.y;
	axb.y = -(a.x * b.z - a.z * b.x);
	axb.z = a.x * b.y - a.y * b.x;
	return (axb);
}
