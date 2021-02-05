/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   debug.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/05 10:32:32 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/05 12:06:01 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

#include <stdio.h>
#include "vectors.h"
#include "minirt.h"

void	print_vec(t_vec3 v);
void	print_vec_wrap(t_vec3 v, t_data *data);
int		debug_ray(t_data *data, int x, int y);
void	print_matrix(t_m33 m);
void	print_matrix_wrap(t_m33 m, t_data *data);

#endif
