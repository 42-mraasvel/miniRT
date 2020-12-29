/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersection.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/29 22:42:44 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/29 22:56:42 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

/*
** Goal: Find nearest POSITIVE intersection
*/

double	ray_intersection(t_vec3 origin, t_vec3 direction, t_objects objects)
{
	double	t;

	t = 0.0;
	t = intersect_spheres(origin, direction, objects.spheres);
	return (t);
}
