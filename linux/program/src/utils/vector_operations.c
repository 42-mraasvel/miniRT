/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_operations.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/28 20:21:54 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/28 20:28:50 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "prototypes.h"

double	vec_dot(t_vec3 a, t_vec3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

double	vec_magnitude(t_vec3 v)
{
	return (sqrt(vec_dot(v, v)));
}

t_vec3	vec_normalize(t_vec3 v)
{
	double	m;

	m = vec_magnitude(v);
	if (m == 1 || m == 0)
		return (v);
	m = 1 / m;
	return (vec_gen(v.x * m, v.y * m, v.z * m));
}

t_vec3	vec_add(t_vec3 a, t_vec3 b)
{
	return (vec_gen(a.x + b.x, a.y + b.y, a.z + b.z));
}

t_vec3	vec_sub(t_vec3 a, t_vec3 b)
{
	return (vec_gen(a.x - b.x, a.y - b.y, a.z - b.z));
}
