/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/03 19:29:28 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/03 21:47:28 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <float.h>
#include "scene.h"
#include "raytracing.h"

/*
** Topleft of image plane in 3D coordinates
** using local camera coordinate system
*/

t_vec3	compute_topleft(t_camera *camera, t_resolution res)
{
	float	scale_x;
	float	scale_y;
	float	scale_z;
	t_vec3	start;

	scale_x = (float)res.x / 2.f - 0.5;
	scale_y = (float)res.y / 2.f - 0.5;
	scale_z = (float)scale_x / tan(camera->fov / 2.f);
	start = vec_add(camera->pos, vec_scalar(scale_z, camera->cspace.forward));
	start = vec_add(start, vec_scalar(scale_y, camera->cspace.up));
	start = vec_sub(start, vec_scalar(scale_x, camera->cspace.right));
	return (start);
}

/*
** Because we start from top left,
** we add x * right_vector
** and subtract y * up_vector
*/

t_vec3	compute_pixel(t_vec3 topleft, t_camera *camera, int x, int y)
{
	topleft = vec_add(topleft, vec_scalar(x ,camera->cspace.right));
	topleft = vec_sub(topleft, vec_scalar(y, camera->cspace.up));
	return (topleft);
}

t_ray	compute_ray(t_vec3 topleft, t_camera *camera, int x, int y)
{
	t_ray	ray;
	t_vec3	pixel;

	pixel = compute_pixel(topleft, camera, x, y);
	ray.dir = vec_sub(pixel, camera->pos);
	vec_normalize(&ray.dir);
	ray.origin = camera->pos;
	ray.obj =  NULL;
	ray.t = FLT_MAX;
	return (ray);
}
