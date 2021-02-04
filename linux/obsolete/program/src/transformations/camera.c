/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   camera.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/01 14:15:01 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/02 16:45:31 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"
#include <X11/keysym.h>
#include <X11/keysymdef.h>

int translate_camera(int keycode, t_camera *camera)
{
	if (keycode == XK_d)
		camera->position = vec_add(camera->position, camera->camera_space.base_x);
	else if (keycode == XK_s)
		camera->position = vec_sub(camera->position, camera->camera_space.base_z);
	else if (keycode == XK_w)
		camera->position = vec_add(camera->position, camera->camera_space.base_z);
	else if (keycode == XK_a)
		camera->position = vec_sub(camera->position, camera->camera_space.base_x);
	else if (keycode == XK_z)
		camera->position = vec_add(camera->position, camera->camera_space.base_y);
	else if (keycode == XK_c)
		camera->position = vec_sub(camera->position, camera->camera_space.base_y);
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
	double theta;
	t_vec3	a;
	t_vec3	b;
	t_vec3	c;

	while (degrees > 360)
		degrees -= 360;
	theta = deg_to_rad(degrees);
	//! smells like matrix in here
	a = vec_scalar(v, cos(theta));
	b = vec_scalar(vec_cross(axis, v), sin(theta));
	c = vec_scalar(axis, vec_dot(axis, v) * (1 - cos(theta)));
	return (vec_add(vec_add(a, b), c));
}

static void rotate_camera_basis(t_camera *camera, t_vec3 axis, double degrees)
{
	camera->camera_space.base_x = rotate_vector(camera->camera_space.base_x, axis, degrees);
	camera->camera_space.base_y = rotate_vector(camera->camera_space.base_y, axis, degrees);
	camera->camera_space.base_z = rotate_vector(camera->camera_space.base_z, axis, degrees);
}

int rotate_camera(int keycode, t_camera *camera)
{
	if (keycode == XK_e)
		rotate_camera_basis(camera, camera->camera_space.base_z, -15);
	else if (keycode == XK_q)
		rotate_camera_basis(camera, camera->camera_space.base_z, 15);
	else if (keycode == XK_Up)
		rotate_camera_basis(camera, camera->camera_space.base_x, -15);
	else if (keycode == XK_Down)
		rotate_camera_basis(camera, camera->camera_space.base_x, 15);
	else if (keycode == XK_Right)
		rotate_camera_basis(camera, camera->camera_space.base_y, 15);
	else if (keycode == XK_Left)
		rotate_camera_basis(camera, camera->camera_space.base_y, -15);
	else
		return (false);
	return (true);
}