/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_operations2.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/29 19:15:14 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/29 20:03:46 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "minirt.h"

t_vec3	vec_cross(t_vec3 a, t_vec3 b)
{
	t_vec3	c;

	c.x = a.y * b.z - a.z * b.y;
	c.y = a.x * b.z - a.z * b.x;
	c.z = a.x * b.y - a.y * b.x;
	return (c);
}

t_vec3	vec_scalar(t_vec3 a, double scalar)
{
	t_vec3	c;

	c.x = a.x * scalar;
	c.y = a.y * scalar;
	c.z = a.z * scalar;
	return (c);
}

t_vec3	vec_rotate_x(t_vec3 a, double rad)
{
	t_vec3	result;

	result.x = a.x;
	result.y = a.y * cos(rad) + a.z * sin(rad);
	result.z = a.y * -sin(rad) + a.z * cos(rad);
	return (result);
}

t_vec3	vec_rotate_y(t_vec3 a, double rad)
{
	t_vec3	result;

	result.y = a.y;
	result.x = a.x * cos(rad) + a.z * -sin(rad);
	result.z = a.x * sin(rad) + a.z * cos(rad);
	return (result);
}

t_vec3	vec_rotate_z(t_vec3 a, double rad)
{
	t_vec3	result;

	result.z = a.z;
	result.x = a.x * cos(rad) + a.y * sin(rad);
	result.y = a.x * -sin(rad) + a.y * cos(rad);
	return (result);
}
