/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   facing_ratio.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/24 17:20:12 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/01/24 17:56:40 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	get_viewing_direction(t_intersection_data *data, t_camera camera)
{
	data->viewing_direction = vec_normalize(vec_sub(camera.position, data->intersection_point));
}

void	check_normal(t_intersection_data *data)
{
	if (vec_dot(data->viewing_direction, data->surface_normal) < 0)
	{
		vec_invert(&data->surface_normal);
	}
}

//! ratio is a value between 0 and 1, where 1 is max intensity and 0 is black
int shade_color(t_color *color, double ratio)
{
	*color = gen_color(color->rgb.r * ratio, color->rgb.g * ratio, color->rgb.b * ratio);
}

//! wtf how does it even work it looks so good lol
void facing_ratio(t_intersection_data *data)
{
	double ratio;

	ratio = vec_dot(data->viewing_direction, data->surface_normal);
	if (ratio > 1 || ratio < 0)
		return ;
	shade_color(&data->color, ratio);
}
