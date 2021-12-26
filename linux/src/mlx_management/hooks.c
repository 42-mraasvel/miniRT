/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/03 12:26:46 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/19 23:41:24 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <X11/keysym.h>
#include <X11/keysymdef.h>
#include "x_events.h"
#include "minirt.h"
#include "mlx.h"
#include "ft_error.h"
#include "prototypes.h"
#include "render.h"
#include <stdio.h>

static int	key_hook(int keycode, t_data *data)
{
	t_bool	next;

	next = false;
	printf("Key hook\n");
	if (keycode == XK_Tab)
	{
		next_camera(data);
		next = true;
	}
	else if (keycode == XK_Escape)
		exit_program(data);
	else if (translate_camera(keycode, data->active_cam) == true)
		next = true;
	else if (rotate_camera(keycode, data->active_cam) == true)
		next = true;
	if (next == true)
		if (next_frame(data) != success)
			exit_program(data);
	return (success);
}

static int	close_window(t_data *data)
{
	printf("Red cross\n\n");
	data->mlx->destroy = true;
	exit_program(data);
	return (success);
}

int mlx_test(t_data *data)
{
	printf("Exposed\n");
	printf("%p\n", data);
	next_frame(data);
}

void		activate_hooks(t_data *data)
{
	mlx_hook(data->mlx->win_ptr, ClientMessage, StructureNotifyMask, mlx_test, data);
	mlx_key_hook(data->mlx->win_ptr, key_hook, data);
	mlx_hook(data->mlx->win_ptr, ClientMessage, NoEventMask, close_window, data);
}
