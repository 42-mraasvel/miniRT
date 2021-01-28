/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_operations3.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/29 22:39:22 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/01/28 14:30:00 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

/*
** Returns the unit vector from
** point A to point B
*/

t_vec3	vec_dir(t_vec3 a, t_vec3 b)
{
	return (vec_normalize(vec_sub(b, a)));
}

double	vec_square(t_vec3 a)
{
	return (vec_dot(a, a));
}

t_vec3	vec_divide(t_vec3 a, double s)
{
	s = 1 / s;
	return (vec_scalar(a, s));
}

void	vec_invert(t_vec3 *v)
{
	v->x *= -1;
	v->y *= -1;
	v->z *= -1;
}

double	vec_angle(t_vec3 v, t_vec3 u)
{
	return (acos(vec_dot(v, u) / (vec_magnitude(v) * vec_magnitude(u))));
}
