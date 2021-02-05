/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   debug_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/05 10:31:57 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/05 11:05:44 by mraasvel      ########   odam.nl         */
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
	printf("\nDEBUG VEC:\n");
	print_vec(v);
}
