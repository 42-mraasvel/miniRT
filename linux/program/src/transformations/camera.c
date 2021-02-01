/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   camera.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/01 14:45:01 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/01 15:01:07 by mraasvel      ########   odam.nl         */
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
