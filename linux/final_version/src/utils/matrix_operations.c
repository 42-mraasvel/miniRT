/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   matrix_operations.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/03 18:04:21 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/05 12:54:35 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_m33	matrix_gen(t_vec3 c1, t_vec3 c2, t_vec3 c3)
{
	t_m33	matrix;

	matrix.m[0][0] = c1.x;
	matrix.m[1][0] = c1.y;
	matrix.m[2][0] = c1.z;
	matrix.m[0][1] = c2.x;
	matrix.m[1][1] = c2.y;
	matrix.m[2][1] = c2.z;
	matrix.m[0][2] = c3.x;
	matrix.m[1][2] = c3.y;
	matrix.m[2][2] = c3.z;
	return (matrix);
}

t_vec3	matrix_vec_mult(t_m33 m, t_vec3 v)
{
	t_vec3	new;

	new.x = m.m[0][0] * v.x + m.m[0][1] * v.y + m.m[0][2] * v.z;
	new.y = m.m[1][0] * v.x + m.m[1][1] * v.y + m.m[1][2] * v.z;
	new.z = m.m[2][0] * v.x + m.m[2][1] * v.y + m.m[2][2] * v.z;
	return (new);
}

t_m33	matrix_transpose(t_m33 matrix)
{
	int		i;
	int		j;
	t_m33	transposed;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			transposed.m[j][i] = matrix.m[i][j];
			j++;
		}
		i++;
	}
	return (transposed);
}
