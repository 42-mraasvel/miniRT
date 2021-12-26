/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx_wrappers.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/03 13:39:32 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/04/25 20:43:16 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "minirt.h"

void	ft_pixelput(t_img *img, int x, int y, t_col color)
{
	char	*addr;

	if (img->bmp == true)
	{
		y = img->height - y - 1;
		addr = img->addr + (y * img->size_line) + x * (img->bpp);
		addr[0] = color.b;
		addr[1] = color.g;
		addr[2] = color.r;
	}
	else
	{
		addr = img->addr + (y * img->size_line) + x * (img->bpp);
		*(unsigned int*)addr = color.val;
	}
}

int		push_image(t_data *data)
{
	mlx_put_image_to_window(
		data->mlx->mlx_ptr,
		data->mlx->win_ptr,
		data->next_img->img_ptr,
		0, 0);
	return (success);
}
