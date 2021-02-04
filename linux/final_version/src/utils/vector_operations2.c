/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_operations2.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/03 17:40:06 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/04 23:19:14 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "vectors.h"
#include "ft_enum.h"
#include "libft.h"

float	vec_len(t_vec3 v)
{
	return (sqrt(vec_dot(v, v)));
}

void	vec_normalize(t_vec3 *v)
{
	float	len;

	len = vec_len(*v);
	if (len != 0.0 && len != 1.0)
	{
		len = 1 / len;
		v->x = v->x * len;
		v->y = v->y * len;
		v->z = v->z * len;
	}
}

t_vec3	vec_normalized(t_vec3 v)
{
	float	len;

	len = vec_len(v);
	if (len != 0 && len != 1)
	{
		len = 1 / len;
		v.x *= len;
		v.y *= len;
		v.z *= len;
	}
	return (v);
}

t_vec3	vec_sub(t_vec3 a, t_vec3 b)
{
	return (vec_gen(
		a.x - b.x,
		a.y - b.y,
		a.z - b.z));
}

/*
** true: parallel
** false: otherwise
*/

t_bool	vec_parallel(t_vec3 a, t_vec3 b)
{
	if (ft_fabs(vec_dot(a, b)) == vec_len(a) * vec_len(b))
		return (true);
	return (false);
}
