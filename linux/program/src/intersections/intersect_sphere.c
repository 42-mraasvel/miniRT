/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersect_sphere.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/29 22:48:13 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/30 12:06:08 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft.h"
#include "prototypes.h"
#include "headers.h" // rm

double	calculate_discriminant(double b, double c)
{
	double discriminant;

	discriminant = b * b - 4 * c;
	return (discriminant);
}

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
** if t is negative, there is no intersection, because that would be in the opposite direction
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
	discriminant = calculate_discriminant(b, c);
	if (discriminant < 0)
		return (-1);
	return (get_nearest_t(b, discriminant));
}


// static double	intersect_sphere(t_vec3 origin, t_vec3 direction, t_sphere sphere)
// {
	
// }

double	intersect_spheres(t_vec3 origin, t_vec3 direction, t_vect *spheres)
{
	size_t		i;
	t_sphere	*table;
	double		t;
	double		intersection;

	i = 0;
	table = (t_sphere*)spheres->table;
	t = -1.0;
	while (i < spheres->nmemb)
	{
		intersection = intersect_sphere(origin, direction, table[i]);
		if (t < 0)
			t = intersection;
		else if (intersection >= 0)
			t = ft_fmin(t, intersection);
		i++;
	}
	return (t);
}
