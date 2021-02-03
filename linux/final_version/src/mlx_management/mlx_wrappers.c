/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_image.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/03 13:39:32 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/03 13:40:13 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "minirt.h"

int	push_image(t_data *data)
{
	mlx_put_image_to_window(
		data->mlx->mlx_ptr,
		data->mlx->win_ptr,
		data->next_img->img_ptr,
		0, 0);
	return (success);
}
