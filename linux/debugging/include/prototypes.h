/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   prototypes.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/04 18:59:05 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/05 11:03:29 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "lighting.h"
# include "raytracing.h"

void	compute_light_data(
			t_light *lights, size_t nmemb,
			t_hitdata *hitdata, t_vectvp *objects, t_data *data);
t_col	compute_ambient(t_ambient ambient);

t_bool	rotate_camera(int keycode, t_camera *camera);
t_bool	translate_camera(int keycode, t_camera *camera);
void	next_camera(t_data *data);

#endif
