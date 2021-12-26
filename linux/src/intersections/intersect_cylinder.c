/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersect_cylinder.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/04 10:34:04 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/06 10:12:18 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft.h"
#include "raytracing.h"
#include "objects.h"

/*
** Pythagoras theorem
** to check if point lies on
** cylinder or not.
** l = sqrt((P - C)^2 - r^2)
*/

static t_bool	point_in_cyl(double t, t_ray *ray, t_cylinder *cylinder)
{
	double	len;
	t_vec3	point;

	if (t < 1.0e-6)
		return (false);
	point = vec_add(ray->origin, vec_scalar(t, ray->dir));
	len = sqrtf(
			vec_sqrd(vec_sub(point, cylinder->pos)) - cylinder->radius_sqrd);
	if (len > cylinder->height_half)
		return (false);
	return (true);
}

/*
** 1. 2 positive
** 2. 1 positive - easy
** 3. 0 positive - easy
** Outcomes:
** 1. 2 in cylinder
** 2. 1 in cylinder
** 3. 0 in cylinder
** case(1):
** 		return (ft_fmin(t1, t2)))
** case(2):
**		return(1 in cylinder)
** case(3):
**		return(-1)
*/

static double	check_solutions(t_sol solutions, t_ray *ray, t_cylinder *cyl)
{
	double	min;
	double	max;

	min = ft_fmin(solutions.t1, solutions.t2);
	max = ft_fmax(solutions.t1, solutions.t2);
	if (min < 1.0e-6 || max < 1.0e-6)
	{
		if (point_in_cyl(max, ray, cyl) == true)
			return (max);
		return (-1);
	}
	if (point_in_cyl(min, ray, cyl) == true)
		return (min);
	else if (point_in_cyl(max, ray, cyl) == true)
		return (max);
	return (-1);
}

/*
** Check both T's
** because it's possible
** only the larger T
** is valid for cylinders
*/

static t_sol	quadratic_cyl(double a, double b, double c)
{
	double	discriminant;
	t_sol	t;

	discriminant = b * b - 4.f * a * c;
	if (discriminant < 0.0)
	{
		t.t1 = -1;
		t.t2 = -1;
		return (t);
	}
	discriminant = sqrtf(discriminant);
	t.t1 = (-b + discriminant) / (2 * a);
	t.t2 = (-b - discriminant) / (2 * a);
	return (t);
}

/*
** 1. Point line distance formula
** substitute point with ray form
** 2. |(O - C + t * D) x N| = r * |N|
** O = ray origin
** D = ray direction
** C = point on cylinder line
** N = cylinder orientation (normalized)
** r = cylinder radius
** V = (O - C)
**
** Solve for T in quadratic form:
** a = (D x N)^2
** b = 2 * (V x N).(D x N)
** c = (V x N)^2 - r^2
*/

static t_sol	compute_t_cy(t_vec3 norm, t_vec3 dir, t_vec3 v, double r2)
{
	double	a;
	double	b;
	double	c;

	a = vec_sqrd(vec_cross(dir, norm));
	b = 2 * vec_dot(vec_cross(v, norm), vec_cross(dir, norm));
	c = vec_sqrd(vec_cross(v, norm)) - r2;
	return (quadratic_cyl(a, b, c));
}

/*
** 1. Compute intersection with
** infinite cylinder
** 2. Check if point is in range of
** cylinder's height with
** the position being interpreted
** as the center of the cylinder
*/

t_bool			intersect_cylinder(t_ray *ray, void *object)
{
	t_cylinder	*cylinder;
	t_vec3		v;
	t_sol		solutions;
	double		t;

	cylinder = (t_cylinder*)object;
	v = vec_sub(ray->origin, cylinder->pos);
	solutions = compute_t_cy(
		cylinder->orient,
		ray->dir,
		v,
		cylinder->radius_sqrd);
	t = check_solutions(solutions, ray, cylinder);
	if (t < 1.0e-6)
		return (false);
	return (update_ray(ray, t, object));
}
