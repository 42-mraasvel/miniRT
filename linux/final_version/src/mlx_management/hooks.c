/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/03 12:26:46 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/04 19:35:54 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <X11/keysym.h>
#include <X11/keysymdef.h>
#include "minirt.h"
#include "mlx.h"
#include "ft_error.h"
#include "prototypes.h"
#include "render.h"
#include <stdio.h> // rm!

static int	key_hook(int keycode, t_data *data)
{
	t_bool	next;

	next = false;
	printf("Key: %d\n", keycode);
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

static int	close_window(int keycode, t_data *data)
{
	printf("Close hook: %d\n", keycode);
	(void)keycode;
	(void)data;
	return (success);
}

void		activate_hooks(t_data *data)
{
	mlx_key_hook(data->mlx->win_ptr, key_hook, data);
	mlx_hook(data->mlx->win_ptr, 33, 0L, close_window, data);
}
