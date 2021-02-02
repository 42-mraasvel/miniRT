/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/29 13:49:11 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/01 23:26:42 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <X11/keysym.h>
#include <X11/keysymdef.h>
#include "headers.h"

void next_camera(t_data *data)
{
	static size_t camera_index = 0;

	camera_index++;
	if (camera_index == data->scene->cameras->nmemb)
		camera_index = 0;
	printf("Camera: %lu\n", camera_index + 1);
	data->active_camera = &((t_camera*)data->scene->cameras->table)[camera_index];
}

int	key_release(int keycode, t_data *data)
{
	ft_printf("Key release: %d\n", keycode);
}

int	key_hook(int keycode, t_data *data)
{
	ft_printf("Key press: %d\n", keycode);
	// change status to success, and exit on success as well
	if (keycode == XK_Escape)
		free_program(*data, error);
	if (keycode == XK_space)
	{
		next_camera(data);
		if (next_frame(data) != success)
			free_program(*data, error);
	}
	if (translate_camera(keycode, data->active_camera) == true)
		if (next_frame(data) != success)
			free_program(*data, error);
	if (rotate_camera(keycode, data->active_camera) == true)
		if (next_frame(data) != success)
			free_program(*data, error);
	return (success);
}

int	mouse_hook(int keycode, int x, int y, t_data *data)
{
	ft_printf("Mouse: %d - (%d, %d)\n", keycode, x, y);
	return (success);
}

int	expose_hook(t_data *data)
{
	ft_printf("Exposed\n");
	return (success);
}
