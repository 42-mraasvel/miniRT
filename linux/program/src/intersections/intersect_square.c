/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersect_square.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/17 10:22:56 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/01/17 15:05:48 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

t_m34	square_basis(t_square square)
{
	t_vec3	x;
	t_vec3	y;
	t_vec3	z;

	z = square.orientation;
	y = vec_gen(0, 1, 0);
	z = vec_normalize(z);
	if (vec_parallel(z, y) == 0)
		x = vec_cross(z, vec_gen(0, 0, 1));
	else
		x = vec_cross(z, y);
	x = vec_normalize(x);
	y = vec_cross(x, z);
	y = vec_normalize(y);
	return (matrix_assign(x, y, z, vec_gen(0, 0, 0)));
}

/*
** 1. Find intersection between ray and plane on which the square lies
** 2. Create a basis with the square normal as the up axis,
** and the other basis vectors parallel with the sides of the square
** 3. Create a change of basis matrix to express the vector from
** the center of the square to the intersection point in this basis
** 4. Express vector (I - C) in the new basis
** 5. Check if the vector goes outside of the square or not.
** 6. since point.x and point.y represent the lengths of the x and y vectors respectively
** if the absolute length of one is greater than square length / 2 (because the origin is considered the center)
** then the point lies outside of the square
*/

double	intersect_square(t_vec3 origin, t_vec3 direction, t_square square)
{
	double	t;
	t_vec3	point;
	t_m34	cob_matrix;

	t = intersect_plane(origin, direction, square.position, square.orientation);
	if (t < 0)
		return (t);
	point = vec_add(origin, vec_scalar(direction, t));
	cob_matrix = matrix_transpose(square_basis(square));
	point = matrix_vector_mult(cob_matrix, vec_sub(point, square.position));
	if (ft_fabs(point.x) > square.side_size / 2)
		return (-1);
	if (ft_fabs(point.y) > square.side_size / 2)
		return (-1);
	return (t);
}

void	intersect_squares(t_vec3 origin, t_vec3 direction,
		t_vect *squares, t_intersection_data *data)
{
	size_t		i;
	t_square	*table;
	double		intersection;

	i = 0;
	table = (t_square*)squares->table;
	while (i < squares->nmemb)
	{
		intersection = intersect_square(origin, direction, table[i]);
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
				data->surface_normal = table[i].orientation;
			}
		}
		i++;
	}
}
