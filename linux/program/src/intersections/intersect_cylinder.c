/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersect_cylinder.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/20 13:17:49 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/01/25 20:01:34 by mraasvel      ########   odam.nl         */
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

/*
** Source: https://mrl.cs.nyu.edu/~dzorin/rend05/lecture2.pdf
** https://math.stackexchange.com/questions/3248356/calculating-ray-cylinder-intersection-points
** https://math.stackexchange.com/questions/406446/cylinder-ray-intersections-equation
*/

static double	intersect_cylinder(t_vec3 origin, t_vec3 direction, t_cylinder cylinder)
{
	double	a;
	double	b;
	double	c;
	double	discriminant;
	t_vec3 v1;
	t_vec3 v2;
	t_vec3	delta_p;
	
	delta_p = vec_sub(origin, cylinder.position);
	// a = (v - (v . va)va)^2
	// v = ray direction
	// va = cylinder direction
	
	v1 = vec_sub(direction, vec_scalar(cylinder.orientation, vec_dot(direction, cylinder.orientation)));
	a = vec_dot(v1, v1);

	// b = 2(v - (v . va)va . delta_p - (delta_p . va)va)
	v2 = vec_sub(delta_p, vec_scalar(cylinder.orientation, vec_dot(delta_p, cylinder.orientation)));
	b = 2 * vec_dot(v1, v2);

	// c = (delta_p - (delta_p . va)va)^2 - r^2
	c = vec_dot(v2, v2) - (cylinder.diameter / 2 * cylinder.diameter / 2);

	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (-1);
	printf("T: %f\n%f\n", get_nearest_t_cylinder(a, b, discriminant), discriminant);
	print_vec(vec_gen(a, b, c));
	printf("\n");
	return (get_nearest_t_cylinder(a, b, discriminant));
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
