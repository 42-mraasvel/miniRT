/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_operations3.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/29 22:39:22 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/29 23:05:16 by mraasvel      ########   odam.nl         */
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