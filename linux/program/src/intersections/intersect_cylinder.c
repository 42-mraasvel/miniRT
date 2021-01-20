/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersect_cylinder.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/20 13:17:49 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/01/20 17:38:56 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

static double	solve_for_t(double b, double discriminant, int sign)
{
	return ((-b + sign * sqrt(discriminant)) / 2);
}

static double	get_nearest_t(double b, double discriminant)
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

static double	intersect_cylinder(t_vec3 origin, t_vec3 direction, t_cylinder cylinder)
{
	double	a;
	double	b;
	double	c;
	t_vec3 tmp;
	t_vec3 cip;

	tmp = vec_sub(direction, vec_scalar(cylinder.orientation, vec_dot(direction, cylinder.orientation)));
	a = vec_dot(tmp, tmp);
	cip = vec_sub(origin, cylinder.position);
	tmp = vec_sub(direction, vec_dot(vec_dot(vec_dot(direction, cylinder.orientation), cylinder.orientation), cip));
	tmp = vec_sub(tmp, vec_dot(vec_dot(cip, cylinder.orientation), cylinder.orientation));
	b = vec_scalar(tmp, 2);
	tmp = vec_sub(cip, vec_dot(vec_dot(cip, cylinder.orientation), cylinder.orientation));
	c = vec_dot(tmp, tmp) - (cylinder.diameter / 2) * (cylinder.diameter/2)

	double discriminant = (b * b) - 4 * c;
	double t = get_nearest_t(b, discriminant);

	return (t);
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
