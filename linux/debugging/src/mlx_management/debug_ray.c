/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   debug_ray.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/05 10:54:49 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/05 11:07:05 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <float.h>
#include "debug.h"
#include "minirt.h"
#include "raytracing.h"

int	debug_ray(t_data *data, int x, int y)
{
	t_vec3	topleft;
	t_vec3	pixel;
	t_ray	debug_ray;

	topleft = compute_topleft(data->active_cam, data->scene->resolution);
	pixel = compute_pixel(topleft, data->active_cam, x, y);
	debug_ray.dir = vec_normalized(vec_sub(pixel, data->active_cam->pos));
	debug_ray.origin = data->active_cam->pos;
	debug_ray.t = FLT_MAX;
	t_col color = compute_color(debug_ray, data);
	(void)color;
	// printf("DEBUG COLOR: (%d, %d, %d)\n", color.r, color.g, color.b);
	return (success);
}
