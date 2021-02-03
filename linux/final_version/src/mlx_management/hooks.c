/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/03 12:26:46 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/03 16:02:29 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <X11/keysym.h>
#include <X11/keysymdef.h>
#include "minirt.h"
#include "mlx.h"
#include "ft_error.h"
#include <stdio.h> // rm!

static int	key_hook(int keycode, t_data *data)
{
	printf("Key: %d\n", keycode);
	// if (keycode == XK_Escape)
	// 	exit_program(data);
	(void)keycode;
	(void)data;
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
