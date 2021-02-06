/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersect_square.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/04 09:36:21 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/06 10:10:26 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include "raytracing.h"
#include "libft.h"
#include "debug.h"

static t_bool	point_in_square(t_vec3 point, t_square *square)
{
	t_vec3	local;
	double	half_size;

	half_size = square->size / 2.0;
	local = matrix_vec_mult(square->cob_matrix, vec_sub(point, square->pos));
	if (ft_fabs(local.x) > half_size || ft_fabs(local.y) > half_size)
		return (false);
	return (true);
}

/*
** 1. Intersect plane square
** lies on
** 2. Convert point to local
** square coordinate system
** 3. Check up and right vectors
** if they fit inside the square
*/

t_bool			intersect_square(t_ray *ray, void *object)
{
	t_square	*square;
	double		t;
	t_vec3		intersection;

	square = (t_square*)object;
	t = intersect_plane_wrap(*ray, square->norm, square->pos);
	if (t < 1.0e-6)
		return (false);
	intersection = vec_add(ray->origin, vec_scalar(t, ray->dir));
	if (point_in_square(intersection, square) == false)
		return (false);
	return (update_ray(ray, t, object));
}

static t_bool	point_in_square_debug(t_vec3 point, t_square *square, t_data *data)
{
	t_vec3	local;
	double	half_size;

	half_size = square->size / 2.0;
	local = matrix_vec_mult(square->cob_matrix, vec_sub(point, square->pos));
	if (ft_fabs(local.x) > half_size || ft_fabs(local.y) > half_size)
		return (false);
	(void)data;
	return (true);
}

t_bool	intersect_square_debug(t_ray *ray, void *object, t_data *data)
{
	t_square	*square;
	double		t;
	t_vec3		intersection;

	square = (t_square*)object;
	t = intersect_plane_wrap(*ray, square->norm, square->pos);
	if (t < 1.0e-6)
		return (false);
	print_matrix_wrap(square->cob_matrix, data);
	intersection = vec_add(ray->origin, vec_scalar(t, ray->dir));
	if (point_in_square_debug(intersection, square, data) == false)
		return (false);
	(void)data;
	return (update_ray(ray, t, object));
}
