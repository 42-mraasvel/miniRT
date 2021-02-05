/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_operations1.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/03 16:19:01 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/05 00:21:18 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_vec3	vec_gen(double x, double y, double z)
{
	t_vec3	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

double	vec_dot(t_vec3 a, t_vec3 b)
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
	return (vec_gen(
		a.y * b.z - a.z * b.y,
		-(a.x * b.z - a.z * b.x),
		a.x * b.y - a.y * b.x));
}

t_vec3	vec_scalar(double scalar, t_vec3 v)
{
	return (vec_gen(
		v.x * scalar,
		v.y * scalar,
		v.z * scalar));
}

t_vec3	vec_add(t_vec3 a, t_vec3 b)
{
	return (vec_gen(
		a.x + b.x,
		a.y + b.y,
		a.z + b.z));
}
