/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/29 13:49:11 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/29 15:07:09 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <X11/keysym.h>
#include <X11/keysymdef.h>
#include "headers.h"

int	key_hook(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		free_program(*data, success);
	if (next_frame(data) != success)
		free_program(*data, error);
	ft_printf("Key: %d\n", keycode);
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
