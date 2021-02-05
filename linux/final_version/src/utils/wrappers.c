/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wrappers.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/03 22:48:37 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/04 20:37:41 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"
#include "raytracing.h"
#include "objects.h"

float	intersect_plane_wrap(t_ray ray, t_vec3 norm, t_vec3 pos)
{
	t_plane	plane;

	plane.norm = norm;
	plane.pos = pos;
	if (intersect_plane(&ray, &plane) == false)
		return (-1);
	return (ray.t);
}

t_bool	update_ray(t_ray *ray, float t, void *object)
{
	if (t > ray->t)
		return (false);
	ray->t = t;
	ray->obj = object;
	return (true);
}
