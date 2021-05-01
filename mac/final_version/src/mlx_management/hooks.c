/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/03 12:26:46 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/03/10 17:59:05 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mac_mlx_keys.h"
#include "minirt.h"
#include "mlx.h"
#include "ft_error.h"
#include "prototypes.h"
#include "render.h"

static int	key_hook(int keycode, t_data *data)
{
	t_bool	next;

	next = false;
	if (keycode == K_TAB)
	{
		next_camera(data);
		next = true;
	}
	else if (keycode == K_ESC)
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
	exit_program(data);
	return (success);
}

void	activate_hooks(t_data *data)
{
	mlx_key_hook(data->mlx->win_ptr, key_hook, data);
	mlx_hook(data->mlx->win_ptr, 17, 0L, close_window, data);
}
