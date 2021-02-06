/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersect_sphere.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/03 20:09:25 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/06 10:17:21 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ft_enum.h"
#include "scene.h"
#include "raytracing.h"
#include "objects.h"

/*
** a is always equal to one
** because it's a unit vector
*/

static double	compute_t(t_ray *ray, t_sphere *sphere)
{
	double		b;
	double		c;
	t_vec3		v;

	v = vec_sub(ray->origin, sphere->pos);
	b = 2 * vec_dot(v, ray->dir);
	c = vec_dot(v, v) - (sphere->radius * sphere->radius);
	return (quadratic_equation(1.f, b, c));
}

/*
** Vector (Intersection - Center) = radius
** Where intersection = Origin + t * direction
*/

t_bool			intersect_sphere(t_ray *ray, void *object)
{
	t_sphere	*sphere;
	double		t;

	sphere = (t_sphere*)object;
	t = compute_t(ray, sphere);
	if (t < 1.0e-6)
		return (false);
	return (update_ray(ray, t, object));
}
