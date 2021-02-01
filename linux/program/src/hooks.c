/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/29 13:49:11 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/01 14:56:20 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <X11/keysym.h>
#include <X11/keysymdef.h>
#include "headers.h"

int	key_hook(int keycode, t_data *data)
{
	ft_printf("Key: %d\n", keycode);
	// change status to success, and exit on success as well
	if (keycode == XK_Escape)
		free_program(*data, error);
	if (keycode == XK_space)
		if (next_frame(data) != success)
			free_program(*data, error);
	if (translate_camera(keycode, data->active_camera) == true)
		next_frame(data);
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
