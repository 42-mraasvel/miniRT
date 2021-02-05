/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersection.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/29 22:42:44 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/01/28 23:50:11 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "prototypes.h"
#include "headers.h" // rm

/*
** Goal: Find nearest POSITIVE intersection
*/

int	ray_intersection(t_vec3 origin, t_vec3 direction, t_objects objects, t_intersection_data *data)
{
	intersect_spheres(origin, direction, objects.spheres, data);
	intersect_planes(origin, direction, objects.planes, data);
	intersect_triangles(origin, direction, objects.triangles, data);
	intersect_squares(origin, direction, objects.squares, data);
	intersect_cylinders(origin, direction, objects.cylinders, data);
	if (data->t < 0.0)
		return (error);
	data->surface_normal = vec_normalize(data->surface_normal);
	return (success);
}
