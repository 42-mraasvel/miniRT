/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_resolution.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/01 12:45:44 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/01 12:52:11 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int check_resolution(t_data *data)
{
	int x;
	int y;

	mlx_get_screen_size(data->mlx->mlx_ptr, &x, &y);
	data->scene->resolution.x = ft_min(data->scene->resolution.x, x);
	data->scene->resolution.y = ft_min(data->scene->resolution.y, y);
	return (success);
}
