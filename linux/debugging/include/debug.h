/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   debug.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/05 10:32:32 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/05 10:57:09 by mraasvel      ########   odam.nl         */
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

#endif
