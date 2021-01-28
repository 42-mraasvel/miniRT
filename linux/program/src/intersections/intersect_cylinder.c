/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersect_cylinder.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/20 13:17:49 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/01/28 14:34:18 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

static double	solve_for_t(double a, double b, double discriminant, int sign)
{
	return ((-b + sign * sqrt(discriminant)) / (2 * a));
}

static double	get_nearest_t_cylinder(double a, double b, double discriminant)
{
	double	t1;
	double	t2;

	t1 = solve_for_t(a, b, discriminant, 1);
	if (discriminant == 0)
		return (t1);
	t2 = solve_for_t(a, b, discriminant, -1);
	if (t1 < 0 || t2 < 0)
		return (ft_fmax(t1, t2));
	return (ft_fmin(t1, t2));
}

static double	get_discriminant(double a, double b, double c)
{
	return (b * b - 4 * a * c);
}

static double	check_height(t_vec3 origin, t_vec3 direction, t_cylinder cylinder, double t)
{
	t_vec3 v;
	t_vec3 intersection;
	double len;

	intersection = vec_add(origin, vec_scalar(direction, t));
	v = vec_sub(intersection, cylinder.position));
	len = cos(vec_angle(v, cylinder.orientation)) * vec_magnitude(v);
	if (len > cylinder.height / 2.0)
		return (-1);
	return (t);
}

/*
** Source: https://mrl.cs.nyu.edu/~dzorin/rend05/lecture2.pdf
** https://math.stackexchange.com/questions/3248356/calculating-ray-cylinder-intersection-points
** https://math.stackexchange.com/questions/406446/cylinder-ray-intersections-equation


Derived from point line distance equation: Area = |N x (P - A)| = |N| * r
where r is the distance from the line to the point
and P = the intersection point = P(t) = O + t * D

N = cylinder orientation
O = position of the camera
D = direction of the ray
r = radius
A = a point on the cylinder axis

a = (N x D)^2
b = 2 * ((N x D) . (N x A) - (N x D) . (N x O))
c = (N x A)^2 + (N x O)^2 - 2 * ((N x A) . (N x O)) - r^2 * |N|^2

attempt 2:


a = ray origin
b = cylinder position
dir = ray direction
d = cylinder orientation
tmp = RayOrigin - CylinderPosition

A = (dir x d)^2
B = 2(tmp x d . dir x d)
C = (tmp x d)^2 - r^2

Right now it only intersects with the infinite cylinder, still have to make it check height intersection.
And calculate the surface normal.

*/

static double	intersect_cylinder(t_vec3 origin, t_vec3 direction, t_cylinder cylinder)
{
	double a;
	double b;
	double c;
	double radius = cylinder.diameter / 2.0;
	double discriminant;
	t_vec3 tmp = vec_sub(origin, cylinder.position);
	t_vec3 v = vec_cross(direction, cylinder.orientation);

	a = vec_dot(v, v);

	b = 2 * (vec_dot(vec_cross(tmp, cylinder.orientation), vec_cross(direction, cylinder.orientation)));
	v = vec_cross(tmp, cylinder.orientation);
	c = vec_dot(v, v) - pow(radius, 2);

	discriminant = get_discriminant(a, b, c);
	if (discriminant < 0.0)
		return (-1);
	double t = get_nearest_t_cylinder(a, b, discriminant);
	return (check_height(origin, direction, cylinder, t));
}

t_vec3	calculate_cylinder_normal(t_cylinder cylinder, t_vec3 intersection_point)
{
	return (vec_gen(0, 0, 0));
}

void intersect_cylinders(t_vec3 origin, t_vec3 direction, t_vect *cylinders, t_intersection_data *data)
{
	size_t		i;
	t_cylinder	*table;
	double		intersection;

	i = 0;
	table = (t_cylinder*)cylinders->table;
	while (i < cylinders->nmemb)
	{
		intersection = intersect_cylinder(origin, direction, table[i]);
		if (intersection >= 0.0)
		{
			if (data->t < 0.0)
				data->t = intersection;
			else
				data->t = ft_fmin(data->t, intersection);
			if (data->t == intersection)
			{
				data->color = table[i].color;
				data->intersection_point = vec_add(origin, vec_scalar(direction, data->t));
				data->surface_normal = calculate_cylinder_normal(table[i], data->intersection_point);
			}
		}
		i++;
	}
}
