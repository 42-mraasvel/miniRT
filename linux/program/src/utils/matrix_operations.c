/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   matrix_operations.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/17 12:30:41 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/01/17 12:57:12 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"

/*
** Initializes to identity matrix
*/

t_m34	matrix_init(void)
{
	t_m34	matrix;

	ft_bzero(&matrix, sizeof(t_m34));
	matrix.m[0][0] = 1;
	matrix.m[1][1] = 1;
	matrix.m[2][2] = 1;
	return (matrix);
}

/*
** Standard matrix vector multiplication
** Column major vector used so:
** Ax = v
*/

t_vec3	matrix_vector_mult(t_m34 a, t_vec3 x)
{
	t_vec3	v;

	v.x = a.m[0][0] * x.x + a.m[0][1] * x.y + a.m[0][2] * x.z;
	v.y = a.m[1][0] * x.x + a.m[1][1] * x.y + a.m[1][2] * x.z;
	v.z = a.m[2][0] * x.x + a.m[2][1] * x.y + a.m[2][2] * x.z;
	return (v);
}

/*
** Same as matrix vector, except
** uses a homogeneous coordinate for the point
** so points can be translated using matrices
*/

t_vec3	matrix_point_mult(t_m34 a, t_vec3 x)
{
	t_vec3	v;

	v.x = a.m[0][0] * x.x + a.m[0][1] * x.y + a.m[0][2] * x.z + a.m[0][3];
	v.y = a.m[1][0] * x.x + a.m[1][1] * x.y + a.m[1][2] * x.z + a.m[1][3];
	v.z = a.m[2][0] * x.x + a.m[2][1] * x.y + a.m[2][2] * x.z + a.m[2][3];
	return (v);
}

/*
** Switch rows and first 3 columns of matrix
** Row 1 becomes column 1 etc ...
*/

t_m34	matrix_transpose(t_m34 matrix)
{
	t_m34	transposed;
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			transposed.m[i][j] = matrix.m[j][i];
			j++;
		}
		i++;
	}
	return (transposed);
}

t_m34	matrix_assign(t_vec3 col1, t_vec3 col2, t_vec3 col3, t_vec3 col4)
{
	t_m34	result;

	result.m[0][0] = col1.x;
	result.m[1][0] = col1.y;
	result.m[2][0] = col1.z;
	result.m[0][1] = col2.x;
	result.m[1][1] = col2.y;
	result.m[2][1] = col2.z;
	result.m[0][2] = col3.x;
	result.m[1][2] = col3.y;
	result.m[2][2] = col3.z;
	result.m[0][3] = col4.x;
	result.m[1][3] = col4.y;
	result.m[2][3] = col4.z;
	return (result);
}
