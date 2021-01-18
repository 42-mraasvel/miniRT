/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersect_plane.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/07 13:31:00 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/01/17 15:17:07 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

/*
** Derived from the plane equation: ax + by + cz = d
*/

double	intersect_plane(t_vec3 origin, t_vec3 direction, t_vec3 position, t_vec3 normal)
{
	double	n_dot_d;

	n_dot_d = vec_dot(normal, direction);
	if (n_dot_d == 0)
		return (-1);
	return ((vec_dot(normal, position) - vec_dot(normal, origin)) / n_dot_d);
	// alternative that's slightly faster
	return ((vec_dot(normal, vec_sub(position, origin))) / n_dot_d);
}

void	intersect_planes(t_vec3 origin, t_vec3 direction, t_vect *planes, t_intersection_data *data)
{
	size_t	i;
	t_plane	*table;
	double	intersection;

	i = 0;
	table = planes->table;
	while (i < planes->nmemb) {
		intersection = intersect_plane(origin, direction, table[i].position, table[i].orientation);
		if (intersection >= 0)
		{
			if (data->t < 0)
				data->t = intersection;
			else
				data->t = ft_fmin(data->t, intersection);
			if (data->t == intersection) {
				data->color = table[i].color;
				data->intersection_point = vec_add(origin, vec_scalar(direction, data->t));
				data->surface_normal = table[i].orientation;
			}
		}
		i++;
	}
}
