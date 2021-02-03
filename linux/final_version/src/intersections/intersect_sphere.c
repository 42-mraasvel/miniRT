/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersect_sphere.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/03 20:09:25 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/03 21:57:12 by mraasvel      ########   odam.nl         */
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

static float	compute_t(t_ray *ray, t_sphere *sphere)
{
	float		b;
	float		c;
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
	float		t;

	sphere = (t_sphere*)object;
	t = compute_t(ray, sphere);
	if (t <= 0 || t > ray->t)
		return (false);
	ray->t = t;
	ray->obj = object;
	return (true);
}
