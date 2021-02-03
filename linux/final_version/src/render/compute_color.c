/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   compute_color.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/03 19:37:44 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/03 19:57:15 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "raytracing.h"
#include "lighting.h"

t_col	compute_color(t_ray primary_ray, t_data *data)
{
	if (trace(&primary_ray, data->scene->objects) == false)
		return (color_gen(0, 0, 0));
		// return (compute_ambient(data->scene->ambient));
	return (color_gen(255,100,75));
}
