/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersect_cylinder.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/20 13:17:49 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/01/20 16:34:12 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

static double	intersect_cylinder(t_vec3 origin, t_vec3 direction, t_cylinder cylinder)
{
	return (-1);
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
