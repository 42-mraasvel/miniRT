/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersect_plane.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/03 21:48:03 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/04 10:53:52 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include "vectors.h"
#include "raytracing.h"

/*
** The dot product of two
** perpendicular vectors is equal to 0
** So N . (P - P') = 0
** Where P is a point on the place,
** and P' is a particular point on the plane;
** in this case our intersection point.
** t = (N . (P - O)) / (N . D)
*/

t_bool	intersect_plane(t_ray *ray, void *object)
{
	t_plane *plane;
	float	t;
	float	denom;

	plane = (t_plane*)object;
	denom = vec_dot(plane->norm, ray->dir);
	if (denom == 0.f)
		return (false);
	t = vec_dot(plane->norm, vec_sub(plane->pos, ray->origin)) / denom;
	if (t <= 0)
		return (false);
	return (update_ray(ray, t, object));
}
