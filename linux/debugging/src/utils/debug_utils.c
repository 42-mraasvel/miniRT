/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   debug_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/05 10:31:57 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/05 12:02:21 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "vectors.h"
#include "minirt.h"

void	print_vec(t_vec3 v)
{
	printf("(%.2f, %.2f, %.2f)\n", v.x, v.y, v.z);
}

void	print_vec_wrap(t_vec3 v, t_data *data)
{
	if (data->DEBUG == false)
		return ;
	printf("\033[33mVECTOR:\n");
	print_vec(v);
	printf("\n\033[0m");
}

void	print_matrix(t_m33 m)
{
	printf("(%.2f, %.2f, %.2f)\n", m.m[0][0], m.m[0][1], m.m[0][2]);
	printf("(%.2f, %.2f, %.2f)\n", m.m[1][0], m.m[1][1], m.m[1][2]);
	printf("(%.2f, %.2f, %.2f)\n", m.m[2][0], m.m[2][1], m.m[2][2]);
}

void	print_matrix_wrap(t_m33 m, t_data *data)
{
	if (data->DEBUG == false)
		return ;
	printf("\033[33mMATRIX:\n");
	print_matrix(m);
	printf("\n\033[0m");
}
