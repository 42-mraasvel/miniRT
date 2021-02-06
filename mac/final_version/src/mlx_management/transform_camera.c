/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   transform_camera.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/04 19:28:32 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/05 19:59:18 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mac_mlx_keys.h"
#include "minirt.h"
#include "ft_enum.h"

void			next_camera(t_data *data)
{
	static size_t	cam_index = 0;

	cam_index++;
	if (cam_index == data->scene->cameras->nmemb)
		cam_index = 0;
	data->active_cam = &((t_camera*)data->scene->cameras->table)[cam_index];
}

t_bool			translate_camera(int keycode, t_camera *camera)
{
	if (keycode == K_D)
		camera->pos = vec_add(camera->pos, camera->cspace.right);
	else if (keycode == K_S)
		camera->pos = vec_sub(camera->pos, camera->cspace.forward);
	else if (keycode == K_W)
		camera->pos = vec_add(camera->pos, camera->cspace.forward);
	else if (keycode == K_A)
		camera->pos = vec_sub(camera->pos, camera->cspace.right);
	else if (keycode == K_SP)
		camera->pos = vec_add(camera->pos, camera->cspace.up);
	else if (keycode == K_C)
		camera->pos = vec_sub(camera->pos, camera->cspace.up);
	else
		return (false);
	return (true);
}

/*
** https://en.wikipedia.org/wiki/Rodrigues%27_rotation_formula
** https://www.youtube.com/watch?v=q-ESzg03mQc
*/

static t_vec3	rotate_vector(t_vec3 v, t_vec3 axis, double degrees)
{
	double	theta;
	t_vec3	a;
	t_vec3	b;
	t_vec3	c;

	while (degrees > 360)
		degrees -= 360;
	theta = deg_to_rad(degrees);
	a = vec_scalar(cos(theta), v);
	b = vec_scalar(sin(theta), vec_cross(axis, v));
	c = vec_scalar(vec_dot(axis, v) * (1 - cos(theta)), axis);
	return (vec_add(vec_add(a, b), c));
}

static void		rotate_camera_basis(
					t_camera *camera, t_vec3 axis, double degrees)
{
	camera->cspace.right = rotate_vector(camera->cspace.right, axis, degrees);
	camera->cspace.up = rotate_vector(camera->cspace.up, axis, degrees);
	camera->cspace.forward = rotate_vector(
								camera->cspace.forward, axis, degrees);
}

t_bool			rotate_camera(int keycode, t_camera *camera)
{
	if (keycode == K_E)
		rotate_camera_basis(camera, camera->cspace.forward, -15);
	else if (keycode == K_Q)
		rotate_camera_basis(camera, camera->cspace.forward, 15);
	else if (keycode == K_AR_U)
		rotate_camera_basis(camera, camera->cspace.right, -15);
	else if (keycode == K_AR_D)
		rotate_camera_basis(camera, camera->cspace.right, 15);
	else if (keycode == K_AR_R)
		rotate_camera_basis(camera, camera->cspace.up, 15);
	else if (keycode == K_AR_L)
		rotate_camera_basis(camera, camera->cspace.up, -15);
	else
		return (false);
	return (true);
}
