/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersect_sphere.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/29 22:48:13 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/31 08:45:00 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft.h"
#include "prototypes.h"
#include "headers.h" // rm

double	solve_for_t(double b, double discriminant, int sign)
{
	return ((-b + sign * sqrt(discriminant)) / 2);
}

double	get_nearest_t(double b, double discriminant)
{
	double	t1;
	double	t2;

	t1 = solve_for_t(b, discriminant, 1);
	if (discriminant == 0)
		return (t1);
	t2 = solve_for_t(b, discriminant, -1);
	if (t1 < 0 || t2 < 0)
		return (ft_fmax(t1, t2));
	return (ft_fmin(t1, t2));
}

/*
** Intersection returns:
** -1 for no intersection
** value of t for nearest intersection:
** if t is negative, there is no intersection,
** because that would be in the opposite direction
*/

double	intersect_sphere(t_vec3 origin, t_vec3 direction, t_sphere sphere)
{
	double	radius;
	double	b;
	double	c;
	double	discriminant;

	radius = sphere.diameter / 2.0;
	b = 2 * vec_dot(direction, vec_sub(origin, sphere.position));
	c = vec_square(vec_sub(origin, sphere.position)) - radius * radius;
	discriminant = (b * b) - 4 * c;
	if (discriminant < 0.0)
		return (-1);
	return (get_nearest_t(b, discriminant));
}

t_vec3	calculate_sphere_normal(t_vec3 center, t_vec3 intersection)
{
	t_vec3	normal;

	normal = vec_sub(intersection, center);
	return (normal);
}

void	intersect_spheres(t_vec3 origin, t_vec3 direction,
		t_vect *spheres, t_intersection_data *data)
{
	size_t		i;
	t_sphere	*table;
	double		intersection;

	i = 0;
	table = (t_sphere*)spheres->table;
	while (i < spheres->nmemb)
	{
		intersection = intersect_sphere(origin, direction, table[i]);
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
				data->surface_normal = calculate_sphere_normal(table[i].position, data->intersection_point);
			}
		}
		i++;
	}
}
